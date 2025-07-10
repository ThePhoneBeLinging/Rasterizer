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
  // (1) Create the texture once (lazy init)
  if (!texture.has_value())
  {
    texture = LoadTextureFromImage(GenImageColor(EnvVariables::screenWidth, EnvVariables::screenHeight, BLANK));
  }

  // (2) Create a stack-allocated flat pixel buffer (Color[])
  const int width = EnvVariables::screenWidth;
  const int height = EnvVariables::screenHeight;

  std::vector<Color> pixelBuffer;
  pixelBuffer.reserve(width * height);

  for (int x = 0; x < height; x++)
  {
    for (int y = 0; y < width; y++)
    {
      auto& p = pixels_[y][x]; // assuming pixels_[y][x] has .r/.g/.b
      pixelBuffer.push_back(Color(p.r, p.g, p.b, 255));
    }
  }

  // (3) Update the texture using the new pixel data
  UpdateTexture(texture.value(), pixelBuffer.data());

  // (4) Draw the updated texture
  DrawTexture(texture.value(), 0, 0, WHITE);
}
