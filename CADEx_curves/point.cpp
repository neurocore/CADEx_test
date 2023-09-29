#include "pch.h"
#include <ostream>
#include <iomanip>
#include "curves.h"

std::ostream & operator << (std::ostream & os, const Point & p)
{
  auto old_precision = os.precision(3);
  os << "("  << std::setfill(' ') << std::setw(5) << p.x
     << ", " << std::setfill(' ') << std::setw(5) << p.y
     << ", " << std::setfill(' ') << std::setw(5) << p.z
     << ")";
  os.precision(old_precision);
  return os;
}

std::ostream & operator << (std::ostream & os, const Vector & v)
{
  auto old_precision = os.precision(3);
  os << "{"  << std::setfill(' ') << std::setw(5) << v.x
     << ", " << std::setfill(' ') << std::setw(5) << v.y
     << ", " << std::setfill(' ') << std::setw(5) << v.z
     << "}";
  os.precision(old_precision);
  return os;
}
