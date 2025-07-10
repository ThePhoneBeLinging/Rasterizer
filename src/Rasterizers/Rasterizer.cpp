//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "Rasterizer.h"

#include <iostream>

#include "../EnvVariables.h"
#include <random>

#include "../MathUtil.h"
#include "../models/Double2.h"
#include "../models/Double3.h"
#include "../models/ImageSlow.h"

void Rasterizer::rasterize(const std::vector<RasModel>& models, ImageSlow& image)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  std::vector<Double2> trianglePoints;
  std::vector<Pixel> triangleColors;

  for (int i = 0; i < EnvVariables::screenWidth; i++)
  {
    for (int j = 0; j < EnvVariables::screenHeight; j++)
    {
      image.pixels_[i][j] = Pixel(0, 0, 0);
    }
  }

  for (const auto& model : models)
  {
    for (int i = 0; i < model.triangles_.size(); i += 3)
    {
      trianglePoints.push_back(MathUtil::WorldToScreen(model.triangles_[i]));
      trianglePoints.push_back(MathUtil::WorldToScreen(model.triangles_[i + 1]));
      trianglePoints.push_back(MathUtil::WorldToScreen(model.triangles_[i + 2]));
      auto color = model.triangleColors_[i / 3];
      triangleColors.emplace_back(color.r, color.g, color.b);
    }
  }
  for (int index = 0; index < trianglePoints.size(); index += 3)
  {
    Double2 p1 = trianglePoints[index];
    Double2 p2 = trianglePoints[index + 1];
    Double2 p3 = trianglePoints[index + 2];

    int minX = std::min(p1.x, std::min(p2.x, p3.x)) - 1;
    int minY = std::min(p1.y, std::min(p2.y, p3.y)) - 1;
    int maxX = std::max(p1.x, std::max(p2.x, p3.x)) + 1;
    int maxY = std::max(p1.y, std::max(p2.y, p3.y)) + 1;
    auto pixel = triangleColors[index / 3];

    for (int i = minX; i < maxX; i++)
    {
      for (int j = minY; j < maxY; j++)
      {
        if (not MathUtil::PointInsideTriangle(p1, p2, p3, {static_cast<double>(i), static_cast<double>(j)}))
        {
          continue;
        }
        image.pixels_[i][j] = pixel;
      }
    }
  }
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Rasterization took: " << duration.count() << "ms" << std::endl;
}
