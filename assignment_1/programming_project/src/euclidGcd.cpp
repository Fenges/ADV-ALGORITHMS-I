#include "../include/headers.hpp"

// C++ Euclid GCD
int euclidGcd(int a, int b)
{
    while (b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

vector<int> extendEuclidGcd(int a, int b, int g, int x, int y)
{
  vector<int> res;
  if (b == 0){
    int arr[] = {a, 1, 0};
    res.assign(arr, arr + 3);
    return res;
  }

  int r = a%b;
  int q = a/b;

  //Recursive call
  res = extendEuclidGcd(b, r, g, x, y);
  g = res.at(0);
  x = res.at(1);
  y = res.at(2);

  int xTemp = x;
  x = y;
  y = xTemp - y*q;

  int resArr[] = {g, x, y};
  res.assign(resArr, resArr + 3);
  return res;
}
