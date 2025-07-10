//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef MATHUTIL_H
#define MATHUTIL_H
#include <random>

#include "raylib.h"
#include "models/Double2.h"
#include "models/Double3.h"


class MathUtil
{
public:
  static bool PointOnRightSideOfLine(Double2 a, Double2 b, Double2 p);
  static bool PointInsideTriangle(Double2 a, Double2 b, Double2 c, Double2 p);
  static double Dot(Double2 a, Double2 b);
  static Double2 Perpendicular(Double2 a);
  static Double2 WorldToScreen(const Double3& vertex);
  static Color RandomColor();

private:
  static inline std::optional<std::mt19937> rng_;
  static inline std::optional<std::uniform_int_distribution<std::mt19937::result_type>> colorDist_;
};


#endif //MATHUTIL_H
