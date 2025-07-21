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
  static Double3 ToWorldPoint(const Double3& point, double yaw, double pitch);
  static std::vector<Double3> GetBasisVectors(double yaw, double pitch);
  static Double3 TransformVector(const Double3& iHat, const Double3& jHat, const Double3& kHat, const Double3& point);
};


#endif //TRANSFORM_H
