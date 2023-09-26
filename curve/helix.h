#pragma once
#include <exception>
#include <cmath>
#include "../curve.h"

class Helix : public Curve
{
  double _r, _step;

public:
  explicit Helix(double r, double step) : _r(r), _step(step)
  {
    if (r < 0) throw new std::exception("Negative radius is not allowed");
  }

  double get_radius() const { return _r; }
  double get_step() const { return _step; }

  Point get_pos(double t) const override
  {
    return { _r * cos(t), _r * sin(t), t * _step / 2.0 / PI };
  }

  Vector get_dt(double t) const override
  {
    return { -_r * sin(t), _r * cos(t), _step / 2.0 / PI };
  }
};
