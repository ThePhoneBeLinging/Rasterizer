//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "Rasterizer.h"

#include <algorithm>

#include "omp.h"
#include <iostream>

#include "../Util/EnvVariables.h"
#include <random>

#include "../Util/MathUtil.h"
#include "../models/Double2.h"
#include "../models/Double3.h"
#include "ImageSlow.h"
#include "../Util/Transformer.h"

void Rasterizer::rasterize(const std::vector<RasModel*>& models, ImageSlow& image,
                           const Rasterization::Camera3D& camera)
{
  std::vector<Double3> trianglePoints;
  std::vector<Pixel> triangleColors;
  image.reset();

  for (const auto& model : models)
  {
    for (int i = 0; i < model->triangles_.size(); i += 3)
    {
      trianglePoints.push_back(camera.WorldToScreen(model->triangles_[i]));
      trianglePoints.push_back(camera.WorldToScreen(model->triangles_[i + 1]));
      trianglePoints.push_back(camera.WorldToScreen(model->triangles_[i + 2]));
      auto color = model->triangleColors_[i / 3];
      triangleColors.emplace_back(color.r, color.g, color.b);
    }
  }
#pragma omp parallel for
  for (int index = 0; index < trianglePoints.size(); index += 3)
  {
    Double3 p1 = trianglePoints[index];
    Double3 p2 = trianglePoints[index + 1];
    Double3 p3 = trianglePoints[index + 2];

    int minX = std::min(p1.x, std::min(p2.x, p3.x)) - 1;
    int minY = std::min(p1.y, std::min(p2.y, p3.y)) - 1;
    int maxX = std::max(p1.x, std::max(p2.x, p3.x)) + 1;
    int maxY = std::max(p1.y, std::max(p2.y, p3.y)) + 1;
    const auto& pixel = triangleColors[index / 3];

    if (minX > EnvVariables::screenWidth || minY > EnvVariables::screenHeight || maxX < 0 || maxY < 0)
    {
      continue;
    }
    maxX = std::clamp(maxX, 0, EnvVariables::screenWidth - 1);
    maxY = std::clamp(maxY, 0, EnvVariables::screenHeight - 1);

    for (int i = minX; i < maxX; i++)
    {
      for (int j = minY; j < maxY; j++)
      {
        auto weights = Double3(0, 0, 0);
        if (not MathUtil::PointInsideTriangle({p1.x, p1.y}, {p2.x, p2.y}, {p3.x, p3.y},
                                              {static_cast<double>(i), static_cast<double>(j)}, &weights))
        {
          continue;
        }
        double depth = weights.x * p1.z + weights.y * p2.z + weights.z * p3.z;

        image.setPixelColor(i, j, pixel.r, pixel.g, pixel.b, depth);
      }
    }
  }
}
