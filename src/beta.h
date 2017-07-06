/*
 *  beta.h
 *
 *   Created on: 6-jul-2017
 *       Author: M. El-Kebir
 */

#ifndef BETA_H
#define BETA_H

#include <vector>

class BetaDifference
{
public:
  /// Compute probability Pr(X >= Y) where X~beta(x_a, x_b) and Y~beta(y_a,y_b)
  ///
  /// @param x_a alpha parameter of beta distribution of first random variable
  /// @param x_b beta parameter of beta distribution of first random variable
  /// @param y_a alpha parameter of beta distribution of second random variable
  /// @param y_b beta parameter of beta distribution of second random variable
  static double prob(const int x_a,
                     const int x_b,
                     const int y_a,
                     const int y_b);

  
private:
  typedef std::vector<double> StlDoubleVector;
  
  /// Construct look-up table for log factorials
  ///
  /// @param n Maximum log factorial
  /// @param log_fact Output table
  static void constructLogFactorialTable(const int n);
  
  static double g(int a, int b, int c, int d);
  
  static double h(int a, int b, int c, int d);
  
  static double log_beta(int x, int y);
  
  /// @param log_fact Look-up table for log factorials
  static StlDoubleVector _log_fact;
};

#endif // BETA_H
