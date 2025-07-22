//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "MathUtil.h"
#include <random>
#include "EnvVariables.h"
#include "Transformer.h"

double MathUtil::SignedTriangleArea(const Double2& a, const Double2& b, const Double2& p)
{
  Double2 ap = p - a;
  Double2 abPerp = Perpendicular(b - a);
  return Dot(ap, abPerp) / 2;
}

bool MathUtil::PointInsideTriangle(const Double2& a, const Double2& b, const Double2& c, const Double2& p,
                                   Double3* weights)
{
  double areaABP = SignedTriangleArea(a, b, p);
  double areaBCP = SignedTriangleArea(b, c, p);
  double areaCAP = SignedTriangleArea(c, a, p);
  bool inTriangle = areaABP >= 0 && areaBCP >= 0 && areaCAP >= 0;

  double totalArea = areaABP + areaBCP + areaCAP;
  double invAreaSum = 1 / (areaABP + areaBCP + areaCAP);
  double weightA = areaBCP / invAreaSum;
  double weightB = areaCAP / invAreaSum;
  double weightC = areaABP / invAreaSum;

  *weights = Double3(weightA, weightB, weightC);
  return inTriangle && totalArea > 0;
}

double MathUtil::Dot(const Double2& a, const Double2& b)
{
  return a.x * b.x + a.y * b.y;
}

Double2 MathUtil::Perpendicular(const Double2& a)
{
  return {a.y, -a.x};
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
