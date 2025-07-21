//
// Created by eal on 22/07-2025.
//

#include "Camera3D.h"

#include <cmath>

#include "raylib.h"
#include "../Util/EnvVariables.h"
#include "../Util/Transformer.h"

Rasterization::Camera3D::Camera3D() : position_(0, 0, 0), yaw_(0), pitch_(0),
                                      lastMousePosition_(GetMousePosition().x, GetMousePosition().y)
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
  yaw_ += std::abs(mousePos.y - lastMousePosition_.y) / 800;
  pitch_ += std::abs(mousePos.x - lastMousePosition_.x) / 800;
  lastMousePosition_ = {mousePos.x, mousePos.y};
}

Double2 Rasterization::Camera3D::WorldToScreen(const Double3& vertex) const
{
  auto vertexWorld = Transformer::ToWorldPoint(vertex, this);
  auto vertexView = vertexWorld - position_;
  return {vertexView.x + EnvVariables::screenWidth / 2, vertexView.y + EnvVariables::screenHeight / 2};
}
