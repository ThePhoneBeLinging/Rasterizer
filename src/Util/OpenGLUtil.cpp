//
// Created by Elias Aggergaard Larsen on 13/07-2025.
//

#include "OpenGLUtil.h"
#include <glad/gl.h>
#include <fstream>
#include <iostream>
#include <iterator>

#include "EnvVariables.h"
#include "glm/vec3.hpp"

void OpenGLUtil::initializeOpenGL(const std::string& nameOfApp)
{
  glfwSetErrorCallback(errorCallback);

  // initialize glfw window
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // we want to use the opengl 4.6 core profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // actually create the window
  window_ = glfwCreateWindow(EnvVariables::screenWidth, EnvVariables::screenHeight, nameOfApp.c_str(), nullptr,
                             nullptr);

  // make sure the window creation was successful
  if (!window_)
  {
    std::cerr << "Failed to open GLFW window.\n";
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window_);

  // initialize glad for loading all OpenGL functions
  if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
  {
    std::cerr << "Something went wrong!\n";
    exit(EXIT_FAILURE);
  }

  // print some information about the supported OpenGL version
  const GLubyte* renderer = glGetString(GL_RENDERER);
  const GLubyte* version = glGetString(GL_VERSION);
  std::cout << "Renderer: " << renderer << '\n';
  std::cout << "OpenGL version supported " << version << '\n';

  // register user callbacks
  glfwSetKeyCallback(window_, keyCallback);
  glfwSetMouseButtonCallback(window_, mouseButtonCallback);
  glfwSetCursorPosCallback(window_, mousePositionCallback);
  glfwSetFramebufferSizeCallback(window_, framebufferSizeCallback);

  glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
  shaderProgram_ = createShaderProgram(
    "../Resources/shaders/test.vert.glsl",
    "../Resources/shaders/test.frag.glsl");
}

GLuint OpenGLUtil::createShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
  // create and compile shaders
  GLenum vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderPath);
  GLenum fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderPath);

  // create a shader program, attach both shaders and link them together
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // check for errors while linking the shaders together
  int success;
  char infoLog[512];
  glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(shaderProgram, 512, nullptr, infoLog);
    std::cerr << "Error while linking shaders\n" << infoLog << std::endl;
  }

  // after creating the shader program we don't need the two shaders anymore
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // return the shader program handle
  return shaderProgram;
}

void OpenGLUtil::errorCallback(int error, const char* description)
{
  std::cerr << description;
}

void OpenGLUtil::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  // close window when ESC has been pressed
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void OpenGLUtil::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
}

void OpenGLUtil::mousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
}

void OpenGLUtil::framebufferSizeCallback(GLFWwindow* window, int w, int h)
{
  glViewport(0, 0, w, h);
}

GLuint OpenGLUtil::compileShader(GLenum shaderType, const std::string& shaderSourcePath)
{
  // grab the contents of the file and store the source code in a string
  std::ifstream filestream(shaderSourcePath);
  std::string shaderSource((std::istreambuf_iterator<char>(filestream)),
                           std::istreambuf_iterator<char>());

  // create and compile the shader
  GLuint shaderHandle = glCreateShader(shaderType);
  const char* shaderSourcePtr = shaderSource.c_str();
  glShaderSource(shaderHandle, 1, &shaderSourcePtr, nullptr);
  glCompileShader(shaderHandle);

  // check if compilation was successful
  int success;
  char infoLog[512];
  glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(shaderHandle, 512, nullptr, infoLog);
    std::cerr << "Error while compiling shader\n" << infoLog << std::endl;
  }

  // return the shader handle
  return shaderHandle;
}

GLFWwindow* OpenGLUtil::getWindow()
{
  return window_;
}

void OpenGLUtil::render(std::vector<Model>& models)
{
  auto vao = createBuffers();
  glUseProgram(shaderProgram_);
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

GLuint OpenGLUtil::createBuffers()
{
  // specify the layout of the vertex data, being the vertex position followed by the vertex color
  struct Vertex
  {
    glm::vec3 pos;
    glm::vec3 color;
  };

  // we specify a triangle with red, green, blue at the tips of the triangle
  Vertex vertexData[] = {
    Vertex{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.f, 0.f, 0.f)},
    Vertex{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.f, 1.f, 0.f)},
    Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.f, 0.f, 1.f)}
  };

  // create the vertex array object that holds all vertex buffers
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // create a vertex buffer that contains all vertex positions and copy the vertex positions into that buffer
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

  // we need to tell the buffer in which format the data is and we need to explicitly enable it
  // first we specify the layout of the vertex position
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(struct Vertex, pos)));
  glEnableVertexAttribArray(0);
  // then we specify the layout of the vertex color
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(struct Vertex, color)));
  glEnableVertexAttribArray(1);

  return vao;
}
