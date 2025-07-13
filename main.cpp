#include <chrono>
#include <iostream>
#include "src/Util/Transformer.h"
#include "src/models/ModelLoader.h"
#include "src/Util/OpenGLUtil.h"
#include "glad/gl.h"

int main()
{
  OpenGLUtil::initializeOpenGL("Rasterizer");
  std::vector<Model> models;
  for (int i = 0; i < 1; i++)
  {
    auto cube = ModelLoader::loadModel("../Resources/simpleCube.obj");
    cube = cube * 100;
    cube.setPosition(i * 200 - 400, 0, 0);
    models.push_back(cube);
  }
  while (!glfwWindowShouldClose(OpenGLUtil::getWindow()))
  {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    // clear the back buffer with the specified color and the depth buffer with 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    Transformer::yaw += 1.0f * static_cast<double>(duration.count()) / 1000;
    Transformer::pitch += 1.0f * static_cast<double>(duration.count()) / 1000;
    std::cout << "Drawing took: " << duration.count() << " ms" << std::endl;

    // render to back buffer
    OpenGLUtil::render(models);

    // switch front and back buffers
    glfwSwapBuffers(OpenGLUtil::getWindow());
    glfwPollEvents();
  }

  return 0;
}
