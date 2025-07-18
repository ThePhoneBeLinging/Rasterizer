//
// Created by Elias Aggergaard Larsen on 10/07-2025.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <vector>

#include "models/Double3.h"


class Transformer
{
public:
  static inline double yaw = 0;
  static inline double pitch = 0;
  static Double3 ToWorldPoint(const Double3& point);
  static std::vector<Double3> GetBasisVectors();
  static Double3 TransformVector(const Double3& iHat, const Double3& jHat, const Double3& kHat, const Double3& point);
};


#endif //TRANSFORM_H
