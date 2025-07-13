//
// Created by Elias Aggergaard Larsen on 13/07-2025.
//

#ifndef OPENGLUTIL_H
#define OPENGLUTIL_H
#include <iostream>
#include <string>

#include "glad/gl.h"
#include "GLFW/glfw3.h"


class Model;

class OpenGLUtil
{
public:
  static void initializeOpenGL(const std::string& nameOfApp);
  static GLuint createShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
  static GLFWwindow* getWindow();
  static void render(std::vector<Model>& models);

private:
  static void errorCallback(int error, const char* description);
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
  static void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);

  static void framebufferSizeCallback(GLFWwindow* window, int w, int h);

  static GLuint compileShader(GLenum shaderType, const std::string& shaderSourcePath);

private:
  static inline GLFWwindow* window_ = nullptr;
  static inline GLuint shaderProgram_ = 0;
};


#endif //OPENGLUTIL_H
