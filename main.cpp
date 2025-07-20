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
  std::vector<RasModel*> models;
  auto cube = ModelLoader::getRasModel("simpleCube");
  for (int i = -1; i < 2; i++)
  {
    auto cubeInstance = cube->createInstance();
    cubeInstance->scale_ = 100;
    cubeInstance->position_.x = -200 * i;
    cubeInstance->position_.y = 0;
    cube->generateTriangles();
    models.push_back(cube);
  }
  ImageSlow image = ImageSlow();
  for (int times = 0; times < 2500; times++)
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
