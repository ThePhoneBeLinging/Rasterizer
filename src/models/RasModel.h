//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "Double3.h"
#include "raylib.h"
#include "UsableModel.h"


class RasModel
{
public:
  RasModel() = default;
  std::shared_ptr<UsableModel> createInstance();
  void generateTriangles();
  std::vector<Double3> triangles_;
  std::vector<Color> triangleColors_;
  std::vector<Double3> vertices_;
  std::vector<Double3> faces_;

private:
  std::vector<std::shared_ptr<UsableModel>> instances_;
};


#endif //MODEL_H
