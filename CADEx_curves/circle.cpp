#include "pch.h"
#include "curves.h"

Circle::Circle(double r) : _r(r)
{
  if (r < 0) throw new std::exception("Negative radius is not allowed");
}

Point Circle::get_pos(double t) const
{
  return { _r * cos(t), _r * sin(t), 0 };
}

Vector Circle::get_dt(double t) const
{
  return { -_r * sin(t), _r * cos(t), 0 };
}
