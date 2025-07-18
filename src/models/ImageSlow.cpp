//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#include "ImageSlow.h"

#include <utility>

#include "raylib.h"
#include "../EnvVariables.h"

ImageSlow::ImageSlow() : pixels_(EnvVariables::screenWidth)
{
  for (auto& pixel : pixels_)
  {
    pixel.resize(EnvVariables::screenHeight);
  }
}

void ImageSlow::draw()
{
  if (!texture.has_value())
  {
    texture = LoadTextureFromImage(GenImageColor(EnvVariables::screenWidth, EnvVariables::screenHeight, BLANK));
  }

  const int width = EnvVariables::screenWidth;
  const int height = EnvVariables::screenHeight;

  std::vector<Color> pixelBuffer;
  pixelBuffer.reserve(width * height);

  for (int x = 0; x < height; x++)
  {
    for (int y = 0; y < width; y++)
    {
      auto& p = pixels_[y][x];
      pixelBuffer.push_back(Color(p.r, p.g, p.b, 255));
    }
  }

  UpdateTexture(texture.value(), pixelBuffer.data());
  DrawTexture(texture.value(), 0, 0, WHITE);
}
