
/***************************************************************
|Description: Use Horner's rule to evaluate a polynomial at a
|			  particular v of x from exponent 0 -> n
|Function: hornerEval(a[0:n], v)
|Input: a[0:n] (array of real numbers), v (a real number)
|Output: value of ax^n + ax^(n-1) + ... + ax^1 + a @ x = v
***************************************************************/
int polyEval(int a[], int n, int v) {
	int sum = a[0];

	for (int i = 1; i <= n; ++i) {
		sum = sum * v + a[i];
	}
	return sum;
} // end polyEval
