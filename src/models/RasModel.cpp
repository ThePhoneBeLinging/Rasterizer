//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "RasModel.h"
#include "../MathUtil.h"

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
