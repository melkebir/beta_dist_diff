/*
 *  beta.cpp
 *
 *   Created on: 6-jul-2017
 *       Author: M. El-Kebir
 */

#include "beta.h"
#include <cmath>
#include <cassert>

BetaDifference::StlDoubleVector BetaDifference::_log_fact = BetaDifference::StlDoubleVector();

void BetaDifference::constructLogFactorialTable(const int n)
{
  _log_fact = StlDoubleVector(n+1, 0);
  _log_fact[0] = 0;
  for (int i = 1; i <= n; ++i)
  {
    _log_fact[i] = _log_fact[i - 1] + log(i);
  }
}

double BetaDifference::prob(const int x_a,
                            const int x_b,
                            const int y_a,
                            const int y_b)
{
//  int max_n = std::max();
  int max_n = 2 + x_a + x_b + y_a + y_b;
  
  if (_log_fact.size() <= max_n)
  {
    constructLogFactorialTable(max_n);
  }
  
  // we want to compute the probability that p is an ancestor to q
  if (x_a == 0 && x_b == 0 && y_a == 0 && y_b == 0)
  {
    return 1;
  }
  else if (x_a == 0 && x_b == 0)
  {
    return 0;
  }
  else if (y_a == 0 && y_b == 0)
  {
    return 1;
  }
  else
  {
    return 1 - g(y_a + 1, y_b + 1, x_a + 1, x_b + 1);
  }
}

double BetaDifference::g(int a, int b, int c, int d)
{
  int aa = std::min(a, c);
  int bb = std::min(b, d);
  int cc = aa;
  int dd = bb;
  
  double res = 0.5;
  
  while (aa < a)
  {
    res += h(aa, bb, cc, dd) / aa;
    ++aa;
  }
  
  while (bb < b)
  {
    res -= h(aa, bb, cc, dd) / bb;
    ++bb;
  }
  
  while (cc < c)
  {
    res -= h(aa, bb, cc, dd) / cc;
    ++cc;
  }
  
  while (dd < d)
  {
    res += h(aa, bb, cc, dd) / dd;
    ++dd;
  }
  
  assert(res != INFINITY);
  assert(res != -INFINITY);
  assert(res != NAN);
  
  return res;
}

double BetaDifference::h(int a, int b, int c, int d)
{
  return exp(log_beta(a+c, b+d)
             - (log_beta(a, b) + log_beta(c, d)));
}

double BetaDifference::log_beta(int x, int y)
{
  assert(x + y - 1 < _log_fact.size());
  return _log_fact[x - 1] + _log_fact[y - 1] - _log_fact[x + y - 1];
}
