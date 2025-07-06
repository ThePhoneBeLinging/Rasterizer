//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "SingleTriangleRasterizer.h"
#include "../EnvVariables.h"
#include "../MathUtil.h"
#include "../models/Double2.h"
#include "../models/Double3.h"
#include "../models/ImageSlow.h"

std::unique_ptr<ImageInterface> SingleTriangleRasterizer::rasterize()
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
      if (MathUtil::PointInsideTriangle(p1, p2, p3, {static_cast<double>(i), static_cast<double>(j)}))
      {
        pixels[i][j] = Pixel(255, 0, 0);
      }
    }
  }
  return std::make_unique<ImageSlow>(pixels);
}
