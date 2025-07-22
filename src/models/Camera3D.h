//
// Created by eal on 22/07-2025.
//

#ifndef CAMERA3D_H
#define CAMERA3D_H
#include "Double2.h"
#include "Double3.h"

namespace Rasterization
{
  class Camera3D
  {
  public:
    Camera3D();
    void update();
    [[nodiscard]] Double3 WorldToScreen(const Double3& vertex) const;

    double yaw_;
    double pitch_;

  private:
    Double2 lastMousePosition_;
    Double3 position_;
    static inline constexpr int camSpeed_ = 200;
  };
}


#endif //CAMERA3D_H
