#pragma once
#include <exception>
#include <ostream>
#include <cmath>

#ifdef CURVES_EXPORTS
#define CURVES_API __declspec(dllexport)
#else
#define CURVES_API __declspec(dllimport)
#endif

const double PI = atan(1.0) * 4;


struct CURVES_API Point
{
  double x, y, z;
  Point(double x, double y, double z)
    : x(x), y(y), z(z)
  {}
};

struct CURVES_API Vector : public Point
{
  Vector(double x, double y, double z)
    : Point(x, y, z)
  {}
};

CURVES_API extern std::ostream & operator << (std::ostream & os, const Point & p);
CURVES_API extern std::ostream & operator << (std::ostream & os, const Vector & v);


class CURVES_API Curve
{
public:
  virtual Point get_pos(double t) const = 0;
  virtual Vector get_dt(double t) const = 0;
  virtual ~Curve() {}
};


class CURVES_API Circle : public Curve
{
  double _r;

public:
  explicit Circle(double r);
  double get_radius() const { return _r; }
  Point get_pos(double t) const override;
  Vector get_dt(double t) const override;
};


class CURVES_API Ellipse : public Curve
{
  double _rx, _ry;

public:
  explicit Ellipse(double rx, double ry);
  double get_radius_x() const { return _rx; }
  double get_radius_y() const { return _ry; }
  Point get_pos(double t) const override;
  Vector get_dt(double t) const override;
};


class CURVES_API Helix : public Curve
{
  double _r, _step;

public:
  explicit Helix(double r, double step);
  double get_radius() const { return _r; }
  double get_step() const { return _step; }
  Point get_pos(double t) const override;
  Vector get_dt(double t) const override;
};
