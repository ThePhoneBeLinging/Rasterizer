#include <chrono>
#include <iostream>

#include "raylib.h"
#include "src/EnvVariables.h"
#include "src/Transformer.h"
#include "src/models/ModelLoader.h"
#include "src/Rasterizers/Rasterizer.h"

int main()
{
  InitWindow(EnvVariables::screenWidth, EnvVariables::screenHeight, "Rasterizer");
  std::vector<RasModel> models;
  for (int i = 0; i < 5; i++)
  {
    auto cube = ModelLoader::loadModel("../Resources/simpleCube.obj");
    cube = cube * 100;
    cube.setPosition(i * 200 - 400, 0, 0);
    models.push_back(cube);
  }
  ImageSlow image = ImageSlow();
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    Rasterizer::rasterize(models, image);
    image.draw();
    Transformer::yaw += 1.0f * GetFrameTime();
    Transformer::pitch += 1.0f * GetFrameTime();
    DrawFPS(0, 0);
    EndDrawing();
  }

  return 0;
}
