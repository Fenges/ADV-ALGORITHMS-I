#include <iostream>
#include "header.h"

using namespace std;

int main()
{
  std::cout << "Miller-Rabin Primility Test: " << std::endl;
  int k = 4;  // Number of iterations

  for (int n = 1; n < 100; n++)
    if (isPrime(n, k))
      std::cout << n << " ";

  return 0;
}
