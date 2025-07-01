//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef RASTERIZOR_H
#define RASTERIZOR_H
#include "src/models/ImageInterface.h"


class Rasterizer
{
public:
  Rasterizer() = default;
  std::shared_ptr<ImageInterface> rasterize();
};


#endif //RASTERIZOR_H
