#pragma once
#include "types.h"

class Curve
{
public:
  virtual Point get_pos(double t) const = 0;
  virtual Vector get_dt(double t) const = 0;
  virtual ~Curve() {}
};
