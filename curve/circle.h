#pragma once
#include <exception>
#include <cmath>
#include "../curve.h"

class Circle : public Curve
{
  double _r;

public:
  explicit Circle(double r) : _r(r)
  {
    if (r < 0) throw new std::exception("Negative radius is not allowed");
  }

  double get_radius() const { return _r; }

  Point get_pos(double t) const override
  {
    return { _r * cos(t), _r * sin(t), 0 };
  }

  Vector get_dt(double t) const override
  {
    return { -_r * sin(t), _r * cos(t), 0 };
  }
};
