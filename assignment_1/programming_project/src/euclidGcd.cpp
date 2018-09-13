#include "../include/headers.hpp"

/***************************************************************
|Function: euclidGCD(a, b)
|Input: a, b (both nonnegative integers)
|Output: greatest common divisor
***************************************************************/
int euclidGcd(int a, int b) {
	int remainder;

	// while the remainder of a % b != 0 do:
	while (b != 0) {
		// gcd(a, b) = gcd(a, a % b)
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
} // end euclidGCD

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
