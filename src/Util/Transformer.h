//
// Created by Elias Aggergaard Larsen on 10/07-2025.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <vector>
#include "../models/Camera3D.h"
#include "../models/Double3.h"


class Transformer
{
public:
  static Double3 ToWorldPoint(const Double3& point, const Rasterization::Camera3D* cam);
  static std::vector<Double3> GetBasisVectors(const Rasterization::Camera3D* cam);
  static Double3 TransformVector(const Double3& iHat, const Double3& jHat, const Double3& kHat, const Double3& point);
};


#endif //TRANSFORM_H
