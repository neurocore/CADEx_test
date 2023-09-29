#include "pch.h"
#include "curves.h"

Helix::Helix(double r, double step) : _r(r), _step(step)
{
  if (r < 0) throw new std::exception("Negative radius is not allowed");
}

Point Helix::get_pos(double t) const
{
  return { _r * cos(t), _r * sin(t), t * _step / 2.0 / PI };
}

Vector Helix::get_dt(double t) const
{
  return { -_r * sin(t), _r * cos(t), _step / 2.0 / PI };
}
