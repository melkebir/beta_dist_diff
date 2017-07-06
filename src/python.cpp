/*
 *  python.cpp
 *
 *   Created on: 6-jul-2017
 *       Author: M. El-Kebir
 */

#include <boost/scoped_array.hpp>
#include <boost/python.hpp>
#include <iostream>
#include "beta.h"

namespace p = boost::python;

double prob(int x_a, int x_b, int y_a, int y_b)
{
  double res = BetaDifference::prob(x_a, x_b, y_a, y_b);
  return res;
}

BOOST_PYTHON_MODULE(beta_difference)
{
  p::def("prob", prob);
}
