//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef CUBERASTERIZER_H
#define CUBERASTERIZER_H
#include "IRasterizer.h"
#include "../models/Model.h"

class CubeRasterizer : public IRasterizer
{
public:
  CubeRasterizer();
  std::unique_ptr<ImageInterface> rasterize() override;

private:
  Model cubeModel_;
};


#endif //CUBERASTERIZER_H
