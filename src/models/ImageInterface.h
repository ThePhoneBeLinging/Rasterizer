//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef IMAGEINTERFACE_H
#define IMAGEINTERFACE_H
#include <vector>

#include "Pixel.h"


class ImageInterface
{
public:
  virtual ~ImageInterface() = default;
  virtual void draw() = 0;
};


#endif //IMAGEINTERFACE_H
