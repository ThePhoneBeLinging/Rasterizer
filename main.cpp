#include <chrono>
#include <iostream>

#include "src/Rasterizers/SingleTriangleRasterizer.h"
#include "raylib.h"
#include "src/EnvVariables.h"
#include "src/Transformer.h"
#include "src/models/ModelLoader.h"
#include "src/Rasterizers/Rasterizer.h"

int main()
{
  auto rasterizer = Rasterizer();
  InitWindow(EnvVariables::screenWidth, EnvVariables::screenHeight, "Rasterizer");
  SetTargetFPS(60);
  const auto cube = ModelLoader::loadModel("../Resources/simpleCube.obj");

  std::vector<RasModel> models;
  models.push_back(cube);
  while (!WindowShouldClose())
  {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    const auto image = rasterizer.rasterize(models);
    image->draw();
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    Transformer::yaw += 1.0f * duration.count() / 1000;
    EndDrawing();
  }

  return 0;
}
