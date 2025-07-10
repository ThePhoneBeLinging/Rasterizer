//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "MathUtil.h"

#include <random>
#
#include "EnvVariables.h"
#include "Transformer.h"

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
  return sideAB && sideBC && sideCA;
}

double MathUtil::Dot(Double2 a, Double2 b)
{
  return a.x * b.x + a.y * b.y;
}

Double2 MathUtil::Perpendicular(Double2 a)
{
  return {a.y, -a.x};
}

Double2 MathUtil::WorldToScreen(const Double3& vertex)
{
  auto vertex_world = Transformer::ToWorldPoint(vertex);
  return {
    vertex_world.x + (static_cast<double>(EnvVariables::screenWidth) / 2),
    vertex_world.y + (static_cast<double>(EnvVariables::screenHeight) / 2)
  };
}

Color MathUtil::RandomColor()
{
  std::random_device dev;
  if (not rng_.has_value())
  {
    rng_ = std::mt19937(dev());
    colorDist_ = std::uniform_int_distribution<std::mt19937::result_type>(0, 255);
  }
  auto randInt = []() -> int8_t
  {
    return colorDist_.value()(rng_.value());
  };
  return Color(randInt(), randInt(), randInt(), 255);
}
