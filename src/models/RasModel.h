//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "Double3.h"
#include "raylib.h"


class RasModel
{
public:
  RasModel();
  void generateTriangles();
  void setPosition(double x, double y, double z);
  RasModel operator*(double scale);
  std::vector<Double3> triangles_;
  std::vector<Color> triangleColors_;
  std::vector<Double3> vertices_;
  std::vector<Double3> faces_;

private:
  Double3 offset_;
};


#endif //MODEL_H
