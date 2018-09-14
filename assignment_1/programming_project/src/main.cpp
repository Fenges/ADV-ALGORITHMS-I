#include <string>
#include <tuple>
#include <iostream>
#include "../include/headers.hpp"

using namespace std;

#define BASE 27

int main()
{
  cout << "######################################################### Miller-Rabin Primility Test: " << endl;
  int k = 4;  // Number of iterations

  for (int n = 1; n < 100; n++)
    if (isPrime(n, k))
      cout << n << " ";
  cout << endl;

  cout << "######################################################### Euclid GCD:" << endl;
  cout << "gcd(23, 36) = " << euclidGcd(24, 36) << endl;

  cout << "######################################################### Extended Euclid GCD: " << endl;
  vector<int> extendGcdRes = extendEuclidGcd(56700, 119070, 0, 0, 0);
  cout << extendGcdRes.at(0) << " ";
  cout << extendGcdRes.at(1) << " ";
  cout << extendGcdRes.at(2) << " ";
  cout << endl;

  cout << "######################################################### polyEval: " << endl;
  // this will be set to the message array
  int arr[] = {20, 5, 19, 20}; 
  // get size of array -> sizeof(arr) = 4 * 4 = 16 bytes / sizeof(int) = 4 bytes = 4 values
  int size = (sizeof(arr)) / sizeof(int)) - 1; 
  cout << "polyEval(arr, size, BASE) = " << polyEval(arr, size, BASE) << endl;

  cout << "######################################################### changeBase:" << endl;
  vector<int> convertedNum = changeBase(397838, BASE);
  cout << "changeBase(397838, BASE) = ";
  for(int i = 0; i < convertedNum.size(); i++)
    cout << convertedNum.at(i) << " ";
  cout << endl;

  cout << "#########################################################" << endl;
  return 0;
}
