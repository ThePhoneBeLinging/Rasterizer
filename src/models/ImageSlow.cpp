//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "ImageSlow.h"

#include <utility>

#include "raylib.h"
#include "../EnvVariables.h"

ImageSlow::ImageSlow() : pixelBuffer_(EnvVariables::screenHeight * EnvVariables::screenWidth)
{
  for (auto& pixel : pixelBuffer_)
  {
    pixel.a = 255;
  }
}

void ImageSlow::draw()
{
  if (!texture.has_value())
  {
    texture = LoadTextureFromImage(GenImageColor(EnvVariables::screenWidth, EnvVariables::screenHeight, BLANK));
  }
  UpdateTexture(texture.value(), pixelBuffer_.data());
  DrawTexture(texture.value(), 0, 0, WHITE);
}

void ImageSlow::setPixelColor(const int x, const int y, const int r, const int g, const int b)
{
  const int index = x * EnvVariables::screenWidth + y;
  pixelBuffer_[index].r = r;
  pixelBuffer_[index].g = g;
  pixelBuffer_[index].b = b;
}
