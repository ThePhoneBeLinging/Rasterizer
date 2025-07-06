#include <iostream>

#include "src/Rasterizers/SingleTriangleRasterizer.h"
#include "raylib.h"
#include "src/EnvVariables.h"

int main()
{
  auto rasterizer = SingleTriangleRasterizer();
  InitWindow(EnvVariables::screenWidth, EnvVariables::screenHeight, "Rasterizer");
  //SetTargetFPS(1);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    auto image = rasterizer.rasterize();
    image->draw();
    DrawFPS(0, 0);
    EndDrawing();
  }

  return 0;
}
