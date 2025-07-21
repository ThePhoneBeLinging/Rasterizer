//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "ImageSlow.h"

#include <iostream>
#include <ostream>
#include <utility>

#include "raylib.h"
#include "../Util/EnvVariables.h"

ImageSlow::ImageSlow() : pixelBuffer_(EnvVariables::screenHeight * EnvVariables::screenWidth)
{
#pragma omp parallel for
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

void ImageSlow::setPixelColor(const int x, const int y, const uint8_t r, const uint8_t g, const uint8_t b)
{
  const int index = y * EnvVariables::screenWidth + x;
  pixelBuffer_[index].r = r;
  pixelBuffer_[index].g = g;
  pixelBuffer_[index].b = b;
}

void ImageSlow::reset()
{
#pragma omp parallel for
  for (auto& pixel : pixelBuffer_)
  {
    pixel.r = 0;
    pixel.g = 0;
    pixel.b = 0;
  }
}
