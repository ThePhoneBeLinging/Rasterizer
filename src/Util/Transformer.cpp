//
// Created by Elias Aggergaard Larsen on 10/07-2025.
//

#include "Transformer.h"
#include <cmath>

#include "../models/Camera3D.h"

Double3 Transformer::ToWorldPoint(const Double3& point, const Rasterization::Camera3D* cam)
{
  auto basisVector = GetBasisVectors(cam);
  auto result = GetBasisVectors(cam);
  Double3 iHat = result[0];
  Double3 jHat = result[1];
  Double3 kHat = result[2];
  return TransformVector(iHat, jHat, kHat, point);
}

std::vector<Double3> Transformer::GetBasisVectors(const Rasterization::Camera3D* cam)
{
  std::vector<Double3> basisVectors;
  Double3 iHat_yaw = {std::cos(cam->yaw_), 0, std::sin(cam->yaw_)};
  Double3 jHat_yaw = {0, 1, 0};
  Double3 kHat_yaw = {-std::sin(cam->yaw_), 0, std::cos(cam->yaw_)};

  Double3 iHat_pitch = {1, 0, 0};
  Double3 jHat_pitch = {0, std::cos(cam->pitch_), -std::sin(cam->pitch_)};
  Double3 kHat_pitch = {0, std::sin(cam->pitch_), std::cos(cam->pitch_)};

  Double3 iHat = TransformVector(iHat_yaw, jHat_yaw, kHat_yaw, iHat_pitch);
  Double3 jHat = TransformVector(iHat_yaw, jHat_yaw, kHat_yaw, jHat_pitch);
  Double3 kHat = TransformVector(iHat_yaw, jHat_yaw, kHat_yaw, kHat_pitch);

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
