//
// Created by Elias Aggergaard Larsen on 02/07-2025.
//

#ifndef IRASTERIZER_H
#define IRASTERIZER_H
#include <memory>
#include "../models/ImageInterface.h"


class IRasterizer
{
public:
  virtual ~IRasterizer() = default;
  virtual std::unique_ptr<ImageInterface> rasterize() = 0;
};


#endif //IRASTERIZER_H
