//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef RASTERIZER_H
#define RASTERIZER_H
#include <memory>
#include "../models/RasModel.h"
#include "../models/ImageSlow.h"


class Rasterizer
{
public:
  static void rasterize(const std::vector<RasModel*>& models, ImageSlow& image);
};


#endif //RASTERIZER_H
