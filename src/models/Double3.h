//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef DOUBLE3_H
#define DOUBLE3_H


class Double3
{
public:
  Double3(double x, double y, double z);
  Double3 operator*(const double& b) const;
  Double3 operator+(Double3 b) const;
  Double3 operator-(const Double3& double3) const;
  double x;
  double y;
  double z;
};


#endif //DOUBLE3_H
