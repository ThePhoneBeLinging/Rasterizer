//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "SingleTriangleRasterizer.h"

#include <iostream>
#include <ostream>
#include <random>

#include "../EnvVariables.h"
#include "../MathUtil.h"
#include "../models/Double2.h"
#include "../models/Double3.h"
#include "../models/ImageSlow.h"

std::unique_ptr<ImageInterface> SingleTriangleRasterizer::rasterize()
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> randX(0, 1280); // distribution in range [1, 6]
  std::uniform_int_distribution<std::mt19937::result_type> randY(0, 720); // distribution in range [1, 6]
  std::uniform_int_distribution<std::mt19937::result_type> randColor(0, 255); // distribution in range [1, 6]

  std::vector<std::vector<Pixel>> pixels(EnvVariables::screenWidth);
  for (int _ = 0; _ < 50; _++)
  {
    Double2 p1 = Double2(randX(rng), randY(rng));
    Double2 p2 = Double2(randX(rng), randY(rng));
    Double2 p3 = Double2(randX(rng), randY(rng));

    int red = randColor(rng);
    int green = randColor(rng);
    int blue = randColor(rng);

    int minX = std::min(p1.x, std::min(p2.x, p3.x));
    int minY = std::min(p1.y, std::min(p2.y, p3.y));
    int maxX = std::max(p1.x, std::max(p2.x, p3.x));
    int maxY = std::max(p1.y, std::max(p2.y, p3.y));


    for (int i = minX; i < maxX; i++)
    {
      pixels[i].resize(EnvVariables::screenHeight);
      for (int j = minY; j < maxY; j++)
      {
        if (not MathUtil::PointInsideTriangle(p1, p2, p3, {static_cast<double>(i), static_cast<double>(j)}))
        {
          continue;
        }
        pixels[i][j] = Pixel(red, green, blue);
      }
    }
  }
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Pixel calculation took: " << duration.count() << "ms" << std::endl;
  return std::make_unique<ImageSlow>(pixels);
}
