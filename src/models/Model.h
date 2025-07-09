//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "Double3.h"


class Model
{
public:
  Model() = default;
  void setVertices(std::vector<Double3> vertices);
  void setFaces(std::vector<Double3> faces);

private:
  std::vector<Double3> vertices_;
  std::vector<Double3> faces_;
};


#endif //MODEL_H
