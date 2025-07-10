//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef RASTERIZER_H
#define RASTERIZER_H
#include <memory>
#include "../models/ImageInterface.h"
#include "../models/RasModel.h"


class Rasterizer
{
public:
  std::unique_ptr<ImageInterface> rasterize(const std::vector<RasModel>& models);
};


#endif //RASTERIZER_H
