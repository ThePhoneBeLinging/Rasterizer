//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "Model.h"
#include "../Util/MathUtil.h"
#include "glm/vec3.hpp"

struct Vertex
{
  glm::vec3 pos;
  glm::vec3 color;
};

Model::Model() : offset_(0, 0, 0)
{
}

GLuint Model::getVBO() const
{
  Vertex vertexData[] = {
    Vertex{glm::vec3(trianglePoints[0].x, trianglePoints[0].y, trianglePoints[0].z), glm::vec3(1.f, 0.f, 0.f)},
    Vertex{glm::vec3(trianglePoints[1].x, trianglePoints[1].y, trianglePoints[1].z), glm::vec3(1.f, 0.f, 0.f)},
    Vertex{glm::vec3(trianglePoints[2].x, trianglePoints[2].y, trianglePoints[2].z), glm::vec3(1.f, 0.f, 0.f)},

  };

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
  return vbo;
}

void Model::generateTrianglePoints()
{
  for (const auto& face : faces_)
  {
    trianglePoints.emplace_back(vertices_[face.x]);
    trianglePoints.emplace_back(vertices_[face.y]);
    trianglePoints.emplace_back(vertices_[face.z]);
    triangleColors_.push_back(MathUtil::RandomColor());
  }
}

void Model::setPosition(double x, double y, double z)
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
  generateTrianglePoints();
}

Model Model::operator*(double scale)
{
  Model model = Model();
  model.faces_ = faces_;
  std::vector<Double3> vertices;
  vertices.reserve(vertices_.size());
  for (auto& vertex : vertices_)
  {
    vertices.emplace_back(vertex * scale);
  }
  model.vertices_ = vertices;
  model.generateTrianglePoints();
  return model;
}
