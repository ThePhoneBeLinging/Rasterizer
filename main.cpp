#include <iostream>

#include "src/Rasterizers/SingleTriangleRasterizer.h"
#include "raylib.h"
#include "src/EnvVariables.h"
#include "src/models/ModelLoader.h"
#include "src/Rasterizers/Rasterizer.h"

int main()
{
  auto rasterizer = Rasterizer();
  InitWindow(EnvVariables::screenWidth, EnvVariables::screenHeight, "Rasterizer");
  //SetTargetFPS(1);
  auto cube = ModelLoader::loadModel("../Resources/simpleCube.obj");

  std::vector<RasModel> models;
  models.push_back(cube);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    const auto image = rasterizer.rasterize(models);
    image->draw();
    DrawFPS(0, 0);
    EndDrawing();
  }

  return 0;
}
