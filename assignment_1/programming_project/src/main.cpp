#include <iostream>
#include "headers.hpp"

using namespace std;

int main()
{
  std::cout << "#########################################################" << std::endl;
  std::cout << "Miller-Rabin Primility Test: " << std::endl;
  int k = 4;  // Number of iterations

  for (int n = 1; n < 100; n++)
    if (isPrime(n, k))
      std::cout << n << " ";

  std::cout << "#########################################################" << std::endl;
  std::cout << "Euclid GCD: " << std::endl;
  std::cout << "gcd(23, 36) = " << euclidGcd(24, 36) << std::endl;


  std::cout << "#########################################################" << std::endl;
  return 0;
}
