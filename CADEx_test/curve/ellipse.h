#pragma once
#include <exception>
#include <cmath>
#include "../curve.h"

class Ellipse : public Curve
{
  double _rx, _ry;

public:
  explicit Ellipse(double rx, double ry) : _rx(rx), _ry(ry)
  {
    if (rx < 0) throw new std::exception("Negative radius is not allowed");
    if (ry < 0) throw new std::exception("Negative radius is not allowed");
  }

  double get_radius_x() const { return _rx; }
  double get_radius_y() const { return _ry; }

  Point get_pos(double t) const override
  {
    return { _rx * cos(t), _ry * sin(t), 0 };
  }

  Vector get_dt(double t) const override
  {
    return { -_rx * sin(t), _ry * cos(t), 0 };
  }
};
