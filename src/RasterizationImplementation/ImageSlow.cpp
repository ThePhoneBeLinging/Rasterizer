//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "ImageSlow.h"

#include <iostream>
#include <limits.h>
#include <ostream>
#include <utility>

#include "raylib.h"
#include "../Util/EnvVariables.h"

ImageSlow::ImageSlow() : pixelBuffer_(EnvVariables::screenHeight * EnvVariables::screenWidth),
                         depthBuffer_(EnvVariables::screenHeight * EnvVariables::screenWidth)
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

void ImageSlow::setPixelColor(const int x, const int y, const uint8_t r, const uint8_t g, const uint8_t b, double depth)
{
  const int index = y * EnvVariables::screenWidth + x;
  if (depthBuffer_[index] < depth)
  {
    return;
  }
  pixelBuffer_[index].r = r;
  pixelBuffer_[index].g = g;
  pixelBuffer_[index].b = b;
  depthBuffer_[index] = depth;
}

void ImageSlow::reset()
{
#pragma omp parallel for
  for (int i = 0; i < EnvVariables::screenWidth * EnvVariables::screenHeight; i++)
  {
    pixelBuffer_[i].r = 0;
    pixelBuffer_[i].g = 0;
    pixelBuffer_[i].b = 0;
    depthBuffer_[i] = INT_MAX;
  }
}
