//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "MathUtil.h"

bool MathUtil::PointOnRightSideOfLine(Double2 a, Double2 b, Double2 p)
{
  Double2 ap = p - a;
  Double2 abPerp = Perpendicular(b - a);
  return Dot(ap, abPerp) >= 0;
}

bool MathUtil::PointInsideTriangle(Double2 a, Double2 b, Double2 c, Double2 p)
{
  bool sideAB = PointOnRightSideOfLine(a, b, p);
  bool sideBC = PointOnRightSideOfLine(b, c, p);
  bool sideCA = PointOnRightSideOfLine(c, a, p);
  return sideAB == sideBC && sideBC == sideCA;
}

double MathUtil::Dot(Double2 a, Double2 b)
{
  return a.x * b.x + a.y * b.y;
}

Double2 MathUtil::Perpendicular(Double2 a)
{
  return {a.y, -a.x};
}
