//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "Double2.h"

#include <cassert>

Double2::Double2(double x, double y) : x(x), y(y)
{
}

Double2 Double2::operator+(const Double2& b) const
{
  return {x + b.x, y + b.y};
}

Double2 Double2::operator-(const Double2& b) const
{
  return {x - b.x, y - b.y};
}

Double2 Double2::operator*(const double& b) const
{
  return {x * b, y * b};
}

Double2 Double2::operator/(const double& b) const
{
  assert(b != 0);
  return {x / b, y / b};
}
