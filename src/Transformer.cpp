//
// Created by Elias Aggergaard Larsen on 10/07-2025.
//

#include "Transformer.h"

Double3 Transformer::ToWorldPoint(Double3 point)
{
  auto basisVector = GetBasisVectors();
  auto result = GetBasisVectors();
  Double3 iHat = result[0];
  Double3 jHat = result[1];
  Double3 kHat = result[2];
  return TransformVector(iHat, jHat, kHat, point);
}

std::vector<Double3> Transformer::GetBasisVectors()
{
  std::vector<Double3> basisVectors;
  Double3 iHat = {std::cos(yaw), 0, std::sin(yaw)};
  Double3 jHat = {0, 1, 0};
  Double3 kHat = {-std::sin(yaw), 0, std::cos(yaw)};
  basisVectors.push_back(iHat);
  basisVectors.push_back(jHat);
  basisVectors.push_back(kHat);
  return basisVectors;
}

Double3 Transformer::TransformVector(const Double3& iHat, const Double3& jHat, const Double3& kHat,
                                     const Double3& point)
{
  return iHat * point.x + jHat * point.y + kHat * point.z;
}
