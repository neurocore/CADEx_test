#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <memory>
#include <random>
#include <vector>
#include <omp.h>
#include "curves.h"

using namespace std;

const int N_THREADS = 4;

int main()
{
  random_device rd;
  mt19937 gen(rd());

  auto random = [&gen](double min, double max)
  {
    return min + (max - min) * gen() / gen.max();
  };

  // 1. Vector of random curves

  vector<shared_ptr<Curve>> curves;

  for (int i = 0; i < 6; i++)
  {
    auto ptr1 = make_shared<Circle>(random(3., 8.));
    curves.emplace_back(move(ptr1));

    auto ptr2 = make_shared<Ellipse>(random(3., 8.), random(3., 8.));
    curves.emplace_back(move(ptr2));

    auto ptr3 = make_shared<Helix>(random(3., 8.), random(4., 10.));
    curves.emplace_back(move(ptr3));
  }

  shuffle(curves.begin(), curves.end(), gen);

  cout << "-- Problem 1 --\n";

  const double t = PI / 4;
  for (const auto curve : curves)
  {
    cout << curve->get_pos(t) << " | "
      << curve->get_dt(t) << "\n";
  }

  // 2. Vector of random circles shared from the first container

  vector<shared_ptr<Circle>> circles;
  for (const auto curve : curves)
  {
    auto ptr = dynamic_pointer_cast<Circle>(curve);
    if (ptr != nullptr)
    {
      circles.push_back(ptr);
    }
  }

  sort(circles.begin(), circles.end(), []
  (
    const shared_ptr<Circle> & a,
    const shared_ptr<Circle> & b
  )
  {
    return a->get_radius() < b->get_radius();
  });

  double r_sum = 0.;
  omp_set_num_threads(N_THREADS);
  #pragma omp parallel for
  for (int i = 0; i < circles.size(); i++)
  {
    r_sum += circles[i]->get_radius();
  }

  cout << "\n-- Problem 2 --\n";

  for (const auto circle : circles)
  {
    cout << circle->get_radius() << "\n";
  }
  cout << "Sum of r = " << r_sum << "\n";

  //system("pause");
}
