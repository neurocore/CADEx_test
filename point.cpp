#include <iomanip>
#include "point.h"

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
