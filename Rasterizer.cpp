//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "Rasterizer.h"

#include "src/EnvVariables.h"
#include "src/MathUtil.h"
#include "src/models/Double2.h"
#include "src/models/Double3.h"
#include "src/models/ImageSlow.h"

std::shared_ptr<ImageInterface> Rasterizer::rasterize()
{
  Double2 p1 = Double2(500, 700);
  Double2 p2 = Double2(500, 200);
  Double2 p3 = Double2(1000, 200);

  std::vector<std::vector<Pixel>> pixels(EnvVariables::screenWidth);
  for (int i = 0; i < EnvVariables::screenWidth; i++)
  {
    pixels[i].resize(EnvVariables::screenHeight);
    for (int j = 0; j < EnvVariables::screenHeight; j++)
    {
      if (MathUtil::PointInsideTriangle(p3, p2, p1, {static_cast<double>(i), static_cast<double>(j)}))
      {
        pixels[i][j] = Pixel(255, 0, 0);
      }
    }
  }
  return std::make_shared<ImageSlow>(pixels);
}
