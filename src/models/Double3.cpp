//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "Double3.h"

Double3::Double3(double x, double y, double z) : x(x), y(y), z(z)
{
}

Double3 Double3::operator*(const double& b) const
{
  return {x * b, y * b, z * b};
}

Double3 Double3::operator+(Double3 b) const
{
  return {x + b.x, y + b.y, z + b.z};
}

Double3 Double3::operator-(const Double3& double3) const
{
  return {x - double3.x, y - double3.y, z - double3.z};
}
