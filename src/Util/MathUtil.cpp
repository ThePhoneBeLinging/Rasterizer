//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "MathUtil.h"
#include <random>
#include "EnvVariables.h"
#include "Transformer.h"

bool MathUtil::PointOnRightSideOfLine(const Double2& a, const Double2& b, const Double2& p)
{
  Double2 ap = p - a;
  Double2 abPerp = Perpendicular(b - a);
  return Dot(ap, abPerp) >= 0;
}

bool MathUtil::PointInsideTriangle(const Double2& a, const Double2& b, const Double2& c, const Double2& p)
{
  bool sideAB = PointOnRightSideOfLine(a, b, p);
  bool sideBC = PointOnRightSideOfLine(b, c, p);
  bool sideCA = PointOnRightSideOfLine(c, a, p);
  return sideAB && sideBC && sideCA;
}

double MathUtil::Dot(const Double2& a, const Double2& b)
{
  return a.x * b.x + a.y * b.y;
}

Double2 MathUtil::Perpendicular(const Double2& a)
{
  return {a.y, -a.x};
}

Double2 MathUtil::WorldToScreen(const Double3& vertex)
{
  auto vertex_world = Transformer::ToWorldPoint(vertex);
  return {
    vertex_world.x + EnvVariables::screenWidth / 2, vertex_world.y + EnvVariables::screenHeight / 2
  };
}

Color MathUtil::RandomColor()
{
  if (not rng_.has_value())
  {
    std::random_device dev;
    rng_ = std::mt19937(dev());
    colorDist_ = std::uniform_int_distribution<std::mt19937::result_type>(0, 255);
  }
  auto randInt = []() -> int8_t
  {
    return colorDist_.value()(rng_.value());
  };
  return Color(randInt(), randInt(), randInt(), 255);
}
