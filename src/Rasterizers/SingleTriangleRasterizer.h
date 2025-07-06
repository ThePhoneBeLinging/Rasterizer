//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef RASTERIZOR_H
#define RASTERIZOR_H
#include "../models/ImageInterface.h"
#include "IRasterizer.h"


class SingleTriangleRasterizer : public IRasterizer
{
public:
  SingleTriangleRasterizer() = default;
  std::unique_ptr<ImageInterface> rasterize() override;
};


#endif //RASTERIZOR_H
