#pragma once
#include <functional>

namespace numerical{
  double numericalDeriv1D(double u, std::function<double(double)> f);
  void numericalDeriv3D(double xin, double yin, double zin, double (*f)(double x ,double y,double z ), double &x, double&y, double&z);
};
