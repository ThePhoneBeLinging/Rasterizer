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
  void setPixelColor(int x, int y, uint8_t r, uint8_t g, uint8_t b);
  void reset();

private:
  std::vector<Color> pixelBuffer_;
  std::optional<Texture2D> texture;
};


#endif //IMAGESLOW_H
