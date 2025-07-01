//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef MATHUTIL_H
#define MATHUTIL_H
#include "models/Double2.h"


class MathUtil
{
public:
  static bool PointOnRightSideOfLine(Double2 a, Double2 b, Double2 p);
  static bool PointInsideTriangle(Double2 a, Double2 b, Double2 c, Double2 p);
  static double Dot(Double2 a, Double2 b);
  static Double2 Perpendicular(Double2 a);
};


#endif //MATHUTIL_H
