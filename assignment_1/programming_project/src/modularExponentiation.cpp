/**************************************************************
|Description: For simplicity and optimization, this function 
|             uses the right to left binary modularization
|             method to compute m^y mod p
|Function: modularExponentiation(x, y, p)
|Input:    x (real number), y (positive integer), 
|          p (positive integer)
|Output: x^y mod p
*************************************************************/
unsigned long long modularExponentiation(int x, unsigned long long y, int p) {
	unsigned long long accumPowers = 1;
	unsigned long long pow = x;

	while (y > 0) {
		// if LSB of y is 1 (number is odd)
		if (y % 2) {
			accumPowers *= pow % p;
		}

		// LSB in y is currently 0 (number is even)
		pow *= pow % p;

		y >>= 1;
	}
	return accumPowers;
} // end rightToLeftBinaryExponentiation
