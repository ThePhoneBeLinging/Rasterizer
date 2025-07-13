//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef MODELLOADER_H
#define MODELLOADER_H
#include <vector>
#include "RasModel.h"
#include "Double3.h"


class ModelLoader
{
public:
  static Model loadModel(const std::string& filePath);

private:
  static std::vector<Double3> getObjectVertices(std::string objectPath);
  static std::vector<Double3> getObjectFaces(std::string objectPath);
};


#endif //MODELLOADER_H
