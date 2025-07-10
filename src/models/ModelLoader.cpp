//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "ModelLoader.h"

#include <fstream>
#include <sstream>

#include "../MathUtil.h"

RasModel ModelLoader::loadModel(const std::string& filePath)
{
  auto model = RasModel();
  model.vertices_ = getObjectVertices(filePath);
  model.faces_ = getObjectFaces(filePath);
  for (const auto& face : model.faces_)
  {
    model.triangles_.emplace_back(model.vertices_[face.x]);
    model.triangles_.emplace_back(model.vertices_[face.y]);
    model.triangles_.emplace_back(model.vertices_[face.z]);
    model.triangleColors_.push_back(MathUtil::RandomColor());
  }
  return model;
}

std::vector<Double3> ModelLoader::getObjectVertices(std::string objectPath)
{
  std::vector<Double3> vertices;
  std::ifstream infile(objectPath);
  std::string line;
  while (std::getline(infile, line))
  {
    if (line.empty() || line[0] != 'v' || (line.size() > 1 && line[1] != ' ')) continue;
    std::istringstream iss(line);
    std::string prefix;
    double x, y, z;

    iss >> prefix >> x >> y >> z;

    vertices.emplace_back(x * 300, y * 300, z * 300);
  }
  return vertices;
}

std::vector<Double3> ModelLoader::getObjectFaces(std::string objectPath)
{
  std::vector<Double3> faces;
  std::ifstream infile(objectPath);
  std::string line;

  while (std::getline(infile, line))
  {
    if (line.empty() || line[0] != 'f' || (line.size() > 1 && line[1] != ' ')) continue;

    std::istringstream iss(line);
    std::string prefix;
    iss >> prefix;

    int indices[3];
    std::string vertex;
    int i = 0;
    while (iss >> vertex && i < 3)
    {
      std::istringstream vss(vertex);
      std::string indexStr;
      std::getline(vss, indexStr, '/'); // Get vertex index only
      indices[i++] = std::stoi(indexStr) - 1; // Convert to 0-based index
    }

    if (i == 3)
      faces.emplace_back(indices[0], indices[1], indices[2]);
  }

  return faces;
}
