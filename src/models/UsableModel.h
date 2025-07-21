//
// Created by Elias Aggergaard Larsen on 19/07-2025.
//

#ifndef USABLEMODEL_H
#define USABLEMODEL_H
#include <string>
#include <vector>

#include "Camera3D.h"
#include "Double2.h"
#include "Double3.h"
#include "raylib.h"


class UsableModel
{
public:
  UsableModel();
  Double3 position_;
  double scale_;
  double yaw_{};
  double pitch_{};
};


#endif //USABLEMODEL_H
