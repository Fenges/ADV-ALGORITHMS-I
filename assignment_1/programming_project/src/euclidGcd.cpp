#include "../include/headers.hpp"

/***************************************************************
|Function: euclidGCD(a, b)
|Input: a, b (both nonnegative integers)
|Output: greatest common divisor
***************************************************************/
int euclidGCD(int a, int b) {
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


/***************************************************************
|Function: extendEuclidGCD(a, b, g, s, t)
|Input: a, b (nonnegative integers)
|Output: return g = gcd(a,b) and integers s and t such that 
		 sa + tb = g
***************************************************************/
vector<int> extendEuclidGCD(int a, int b, int g, int s, int t)
{
	vector<int> res(3);
	int q;
	int r;
	int stemp;



	if (b == 0) {
		res[0] = a;  // g
		res[1] = 1;  // s
		res[2] = 0;  // t
		return res;
	}

	r = a % b;
	q = a / b;

	//Recursive call
	res = extendEuclidGCD(b, r, g, s, t);

	// populate result with values
	// obtained through recursive call
	g = res[0];
	s = res[1];
	t = res[2];

	stemp = s;
	s = t;
	t = stemp - t * q;

	// load up result vector
	res[0] = g;  // g
	res[1] = s;  // s
	res[2] = t;  // t

	return res;
}


