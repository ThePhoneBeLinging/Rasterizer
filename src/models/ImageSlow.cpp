//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "ImageSlow.h"

#include <utility>

#include "raylib.h"

ImageSlow::ImageSlow(std::vector<std::vector<Pixel>> pixel) : pixels_(std::move(pixel))
{
}

void ImageSlow::draw()
{
  int x = 0;
  int y = 0;
  for (const auto& vector : pixels_)
  {
    for (const auto& pixel : vector)
    {
      DrawPixel(x, y, Color(pixel.r, pixel.g, pixel.b, 255));
      y++;
    }
    y = 0;
    x++;
  }
}
