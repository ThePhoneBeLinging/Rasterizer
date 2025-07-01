//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef IMAGESLOW_H
#define IMAGESLOW_H
#include "ImageInterface.h"


class ImageSlow : public ImageInterface
{
public:
  explicit ImageSlow(std::vector<std::vector<Pixel>> pixel);
  void draw() override;

private:
  std::vector<std::vector<Pixel>> pixels_;
};


#endif //IMAGESLOW_H
