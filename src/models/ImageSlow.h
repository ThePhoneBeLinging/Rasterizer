//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef IMAGESLOW_H
#define IMAGESLOW_H
#include <optional>
#include <vector>

#include "Pixel.h"
#include "raylib.h"


class ImageSlow
{
public:
  explicit ImageSlow();
  void draw();

  std::vector<std::vector<Pixel>> pixels_;

private:
  std::optional<Texture2D> texture;
};


#endif //IMAGESLOW_H
