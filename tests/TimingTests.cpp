//
// Created by Elias Aggergaard Larsen on 18/07-2025.
//

#ifndef TIMINGTESTS_H
#define TIMINGTESTS_H
#include "../src/Rasterizers/Rasterizer.h"
#include "../src/models/ModelLoader.h"
#include "gtest/gtest.h"

class TimingTests : public testing::Test
{
};

TEST_F(TimingTests, RasterizeTimingTest)
{
  std::vector<RasModel> models;
  for (int i = 0; i < 5; i++)
  {
    auto cube = ModelLoader::loadModel("../Resources/simpleCube.obj");
    cube = cube * 100;
    cube.setPosition(i * 200 - 400, 0, 0);
    models.push_back(cube);
  }
  auto image = ImageSlow();
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000; i++)
  {
    Rasterizer::rasterize(models, image);
  }
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  EXPECT_EQ(duration.count(), 0);
}

TEST_F(TimingTests, ImageSlowTimingTest)
{
  InitWindow(800, 600, "Test Window");
  std::vector<RasModel> models;
  for (int i = 0; i < 5; i++)
  {
    auto cube = ModelLoader::loadModel("../Resources/simpleCube.obj");
    cube = cube * 100;
    cube.setPosition(i * 200 - 400, 0, 0);
    models.push_back(cube);
  }
  auto image = ImageSlow();
  Rasterizer::rasterize(models, image);
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  for (int k = 0; k < 500; k++)
  {
    image.draw();
  }

  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  EXPECT_EQ(duration.count(), 0);
}

#endif //TIMINGTESTS_H
