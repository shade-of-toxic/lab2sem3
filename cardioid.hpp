#pragma once

#include <cmath>
#ifndef M_PI
template <typename T>
T const pi = std::acos(-T(1));
#else
template <typename T>
T const pi = M_PI;
#endif

struct Cardioid
{
private:
  double _a;

public:
  Cardioid(double a = 1) : _a(a) {}
  const double &getA();
  void setA(const double &val)
  {
    _a = val;
  }
  double getR(const double &angle)
  {
    return 2 * _a * (1 - cos(angle));
  }
  double getMaxLengthFromAxis()
  {
    return 3 * _a;
  }
  double getArea()
  {
    return 6 * pi<double> * pow(_a, 2);
  }
  double getArcLength(const double &angle)
  {
    return 8 * _a * (1 - cos(angle / 2));
  }
  double getRadiusOfCurvative(const double &angle)
  {
    // double halfangle = angle/2;
    // double sinhalfangle = sin(halfangle);
    // double mul10 = sinhalfangle*_a;
    // double mul8over3 = mul10*8/3;
    // double a1 = 8./3.*_a;
    return 8. * _a * sin(angle / 2.)/3.;
  }
};