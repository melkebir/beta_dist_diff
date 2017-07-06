/*
 *  main.cpp
 *
 *   Created on: 6-jul-2017
 *       Author: M. El-Kebir
 */

#include <iostream>
#include "beta.h"

int main(int argc, char** argv)
{
  if (argc != 5)
  {
    std::cerr << "Usage: " << argv[0] << " <X_a> <X_b> <Y_a> <Y_b" << std::endl;
    return 1;
  }
  
  int x_a = atoi(argv[1]);
  int x_b = atoi(argv[2]);
  int y_a = atoi(argv[3]);
  int y_b = atoi(argv[4]);
  
  std::cout << "Pr(X >= Y) = " << BetaDifference::prob(x_a, x_b, y_a, y_b)
    << std::endl;
  
  return 0;
}
