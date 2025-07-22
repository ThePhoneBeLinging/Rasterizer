#include <chrono>
#include <iostream>

#include "raylib.h"
#include "src/models/Camera3D.h"
#include "src/Util/EnvVariables.h"
#include "src/Util/Transformer.h"
#include "src/models/ModelLoader.h"
#include "src/RasterizationImplementation/Rasterizer.h"

int main()
{
  InitWindow(EnvVariables::screenWidth, EnvVariables::screenHeight, "Rasterizer");
  auto cam = Rasterization::Camera3D();

  std::vector<RasModel*> models;
  auto cube = ModelLoader::getRasModel("simpleCube");
  for (int i = -1; i < 0; i++)
  {
    auto cubeInstance = cube->createInstance();
    cubeInstance->scale_ = 100;
    cubeInstance->position_.x = -200 * i;
    cubeInstance->position_.y = 0;
    if (i == 0)
    {
      cubeInstance->pitch_ = 150;
    }
  }
  auto monkey = ModelLoader::getRasModel("Suzanne");
  auto monkeyInstance = monkey->createInstance();
  monkeyInstance->scale_ = 100;
  monkey->generateTriangles();
  models.push_back(monkey);
  cube->generateTriangles();
  models.push_back(cube);
  ImageSlow image = ImageSlow();
  while (not WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    Rasterizer::rasterize(models, image, cam);
    image.draw();
    cam.update();
    DrawFPS(0, 0);
    EndDrawing();
  }

  return 0;
}
