//
// Created by eal on 22/07-2025.
//

#include "Camera3D.h"

#include <cmath>

#include "raylib.h"
#include "../Util/EnvVariables.h"
#include "../Util/Transformer.h"

Rasterization::Camera3D::Camera3D() : yaw_(0), pitch_(0),
                                      lastMousePosition_(GetMousePosition().x, GetMousePosition().y),
                                      position_(0, 0, 0)
{
  DisableCursor();
}

void Rasterization::Camera3D::update()
{
  if (IsKeyDown(KEY_A))
  {
    position_.x += camSpeed_ * GetFrameTime();
  }
  if (IsKeyDown(KEY_D))
  {
    position_.x -= camSpeed_ * GetFrameTime();
  }
  if (IsKeyDown(KEY_S))
  {
    position_.z -= camSpeed_ * GetFrameTime();
  }
  if (IsKeyDown(KEY_W))
  {
    position_.z += camSpeed_ * GetFrameTime();
  }
  auto mousePos = GetMousePosition();
  yaw_ += (mousePos.x - lastMousePosition_.x) / 800;
  pitch_ += (mousePos.y - lastMousePosition_.y) / 800;
  SetMousePosition(EnvVariables::screenWidth / 2, EnvVariables::screenHeight / 2);
  lastMousePosition_ = {
    static_cast<double>(EnvVariables::screenWidth / 2), static_cast<double>(EnvVariables::screenHeight / 2)
  };
}

Double3 Rasterization::Camera3D::WorldToScreen(const Double3& vertex) const
{
  auto vertexWorld = Transformer::ToWorldPoint(vertex, yaw_, pitch_);
  auto vertexView = vertexWorld - position_;
  return {vertexView.x + EnvVariables::screenWidth / 2, vertexView.y + EnvVariables::screenHeight / 2, vertexView.z};
}
