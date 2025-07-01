//
// Created by Elias Aggergaard Larsen on 01/07-2025.
//

#ifndef DOUBLE2_H
#define DOUBLE2_H

class Double2
{
public:
  Double2(double x, double y);
  Double2 operator+(const Double2& b) const;
  Double2 operator-(const Double2& b) const;
  Double2 operator*(const double& b) const;
  Double2 operator/(const double& b) const;
  double x;
  double y;
};


#endif //DOUBLE2_H
