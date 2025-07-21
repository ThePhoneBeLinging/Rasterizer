//
// Created by Elias Aggergaard Larsen on 09/07-2025.
//

#include "RasModel.h"
#include "../Util/MathUtil.h"
#include "../Util/Transformer.h"

std::shared_ptr<UsableModel> RasModel::createInstance()
{
  auto instance = std::make_shared<UsableModel>();
  instances_.push_back(instance);
  return instance;
}

void RasModel::generateTriangles()
{
  triangles_.clear();
  triangleColors_.clear();
  for (const auto& instance : instances_)
  {
    for (const auto& face : faces_)
    {
      auto p1 = vertices_[face.x] * instance->scale_ + instance->position_;
      auto p2 = vertices_[face.y] * instance->scale_ + instance->position_;
      auto p3 = vertices_[face.z] * instance->scale_ + instance->position_;
      triangles_.emplace_back(Transformer::ToWorldPoint(p1, instance->yaw_, instance->pitch_));
      triangles_.emplace_back(Transformer::ToWorldPoint(p2, instance->yaw_, instance->pitch_));
      triangles_.emplace_back(Transformer::ToWorldPoint(p3, instance->yaw_, instance->pitch_));
      triangleColors_.push_back(MathUtil::RandomColor());
    }
  }
}
