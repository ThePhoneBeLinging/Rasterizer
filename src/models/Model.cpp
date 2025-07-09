//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "Model.h"

void Model::setVertices(std::vector<Double3> vertices)
{
  vertices_ = vertices;
}

void Model::setFaces(std::vector<Double3> faces)
{
  faces_ = faces;
}
