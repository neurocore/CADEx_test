#pragma once
#include <ostream>

struct Point
{
  double x, y, z;
  Point(double x, double y, double z)
    : x(x), y(y), z(z)
  {}

  friend std::ostream & operator << (std::ostream & os, const Point & p);
};
