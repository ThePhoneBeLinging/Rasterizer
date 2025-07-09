//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "CubeRasterizer.h"

#include "../EnvVariables.h"
#include "../models/ModelLoader.h"

CubeRasterizer::CubeRasterizer()
{
  cubeModel_ = ModelLoader::loadModel("../../../Resources/simpleCube.obj");
}

std::unique_ptr<ImageInterface> CubeRasterizer::rasterize()
{
  for (int i = 0; i < EnvVariables::screenWidth; i++)
  {
    for (int j = 0; j < EnvVariables::screenHeight; j++)
    {
    }
  }
}
