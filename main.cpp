#include <iostream>

#include "Rasterizer.h"
#include "raylib.h"
#include "src/EnvVariables.h"

int main()
{
  auto rasterizer = Rasterizer();
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
