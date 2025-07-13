//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "Double3.h"
#include "glad/gl.h"


class Model
{
public:
  Model();
  GLuint getVBO() const;
  void generateTrianglePoints();
  void setPosition(double x, double y, double z);
  Model operator*(double scale);
  std::vector<Double3> trianglePoints;
  std::vector<Double3> triangleColors_;
  std::vector<Double3> vertices_;
  std::vector<Double3> faces_;

private:
  Double3 offset_;
};


#endif //MODEL_H
