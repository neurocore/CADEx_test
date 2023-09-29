#include "pch.h"
#include "curves.h"

Ellipse::Ellipse(double rx, double ry) : _rx(rx), _ry(ry)
{
  if (rx < 0) throw new std::exception("Negative radius is not allowed");
  if (ry < 0) throw new std::exception("Negative radius is not allowed");
}

Point Ellipse::get_pos(double t) const
{
  return { _rx * cos(t), _ry * sin(t), 0 };
}

Vector Ellipse::get_dt(double t) const
{
  return { -_rx * sin(t), _ry * cos(t), 0 };
}
