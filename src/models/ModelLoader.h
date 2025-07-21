//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#ifndef MODELLOADER_H
#define MODELLOADER_H
#include <map>
#include <vector>
#include "RasModel.h"
#include "Double3.h"
#include "UsableModel.h"


class ModelLoader
{
public:
  static RasModel* getRasModel(const std::string& modelName);

private:
  static void loadModel(const std::string& modelName);
  static std::vector<Double3> getObjectVertices(const std::string& objectPath);
  static std::vector<Double3> getObjectFaces(const std::string& objectPath);

  static inline std::map<std::string, RasModel> modelMap_;
};


#endif //MODELLOADER_H
