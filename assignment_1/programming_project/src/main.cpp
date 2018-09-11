#include <string>
#include <tuple>
#include <iostream>
#include "../include/headers.hpp"

using namespace std;

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
  int arr[] = {20, 5, 19, 20};
  vector<int> polyTest (arr, arr + sizeof(arr) / sizeof(arr[0]));
  cout << "polyEval({20, 5, 19, 20}, 27) = " << polyEval(polyTest, 27) << endl;

  cout << "######################################################### changeBase:" << endl;
  vector<int> convertedNum = changeBase(397838, 27);
  cout << "changeBase(397838, 27) = ";
  for(int i = 0; i < convertedNum.size(); i++)
    cout << convertedNum.at(i) << " ";
  cout << endl;

  cout << "#########################################################" << endl;
  return 0;
}
