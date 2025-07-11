//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "RasModel.h"
#include "../MathUtil.h"

RasModel::RasModel() : offset_(0, 0, 0)
{
}

void RasModel::generateTriangles()
{
  for (const auto& face : faces_)
  {
    triangles_.emplace_back(vertices_[face.x]);
    triangles_.emplace_back(vertices_[face.y]);
    triangles_.emplace_back(vertices_[face.z]);
    triangleColors_.push_back(MathUtil::RandomColor());
  }
}

void RasModel::setPosition(double x, double y, double z)
{
  double deltaX = x - offset_.x;
  double deltaY = y - offset_.y;
  double deltaZ = z - offset_.z;
  for (auto& vertex : vertices_)
  {
    vertex.x += deltaX;
    vertex.y += deltaY;
    vertex.z += deltaZ;
  }
  offset_ = Double3(x, y, z);
  generateTriangles();
}

RasModel RasModel::operator*(double scale)
{
  RasModel model = RasModel();
  model.faces_ = faces_;
  std::vector<Double3> vertices;
  vertices.reserve(vertices_.size());
  for (auto& vertex : vertices_)
  {
    vertices.emplace_back(vertex * scale);
  }
  model.vertices_ = vertices;
  model.generateTriangles();
  return model;
}
