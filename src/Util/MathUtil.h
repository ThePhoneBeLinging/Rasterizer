//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef MATHUTIL_H
#define MATHUTIL_H
#include <optional>
#include <random>

#include "raylib.h"
#include "../models/Double2.h"
#include "../models/Double3.h"


class MathUtil
{
public:
  static double SignedTriangleArea(const Double2& a, const Double2& b, const Double2& p);
  static bool PointInsideTriangle(const Double2& a, const Double2& b, const Double2& c, const Double2& p,
                                  Double3* weights);
  static double Dot(const Double2& a, const Double2& b);
  static Double2 Perpendicular(const Double2& a);
  static Color RandomColor();

private:
  static inline std::optional<std::mt19937> rng_;
  static inline std::optional<std::uniform_int_distribution<std::mt19937::result_type>> colorDist_;
};


#endif //MATHUTIL_H
