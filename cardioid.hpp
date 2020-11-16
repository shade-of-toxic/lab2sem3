#pragma once

#include <stdexcept>
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
Cardioid(double a = 1) {
if (a < 0)
throw std::runtime_error("Param 'a' can't be less than zero!");
}
double const &getA() const;
double &setA(double const &val)
{
if (val < 0)
throw std::runtime_error("Param 'a' can't be less than zero!");
return _a = val;
}
double getR(double const &angle) const { return 2 * _a * (1 - cos(angle)); }
double getMaxLengthFromAxis() const { return 3 * _a; }
double getArea() const { return 6 * pi<double> * pow(_a, 2); }
double getArcLength(double const &angle) const
{
return 8 * _a * (1 - cos(angle / 2));
}
double getRadiusOfCurvative(double const &angle) const
{
return 8. * _a * sin(angle / 2.) / 3.;
}
};
