*#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include <random>

using namespace std;

class RSA {

private:
  int p, q, phi;
  unsigned long long publicKey;
  vector<int> msg_bc;
  int msg_decimal;
  int n;
  int c;
  int privateKey;
  int m;
  vector<int> msg_base27;
  string msg_original;

public:
  // Constructor using initialization list
  RSA() : p(0), q(0) {}
  /*RSA(){
    this->p = 0;
    this->q = 0;
    
    publicKey = 0;
    msg_bc = 0;
    msg_decimal = 0;
    n = 0;
    c = 0;
    privateKey = 0;
    m = 0;
    msg_base27 = 0;
    msg_original = "";
    
  }*/

  void set_p(int p){
    this->p = p;
    cout << ">> p: " << this->p << endl;
  }
  void set_q(int q){
    this->q = q;
    cout << ">> q: " << this->q << endl;
  }
  void set_phi(){
    this->phi = (this->p-1)*(this->q-1);
    cout << ">> phi: " << this->phi << endl;
  }
  void set_publicKey(){
    unsigned long long publicKey = this->getPublicKey();
    this->publicKey = publicKey;
    cout << ">> publicKey: " << this->publicKey << endl;
  }

  void set_msg_bc(){
    vector<int> msg = this->getMsg();
    this->msg_bc = msg;
    cout << ">> msg_bc: " << this->msg_bc.at(0) << endl;
  }

  void set_msg_decimal(){
    this->msg_decimal = this->polyEval(this->msg_bc, 27);
    cout << ">> msg_decimal: " << this->msg_decimal << endl;
  }
  void set_n(){
    this->n = p*q;
    cout << ">> n: " << this->n << endl;
  }
  void set_c(){
    this->c = this->modExp(this->msg_decimal, this->publicKey, this->n);
    cout << ">> c: " << this->c << endl;
  }
  void set_privateKey(){
    this->privateKey = this->getPrivateKey(this->publicKey, this->phi);
    cout << ">> privateKey: " << this->privateKey << endl;
  }
  void set_m(){
    this->m = this->modExp(this->c, this->privateKey, this->n);
    cout << ">> m: " << this->m << endl;
  }
  void set_msg_base27(){
    this->msg_base27 = this->changeBase(this->m, 27);
    cout << ">> msg_base27: " << this->msg_base27.at(0) << endl;
  }
  void set_msg_original(){
    this->msg_original = this->BCtoEng(this->msg_base27);
    cout << ">> msg_original: " << this->msg_original << endl;
  }

  // ############################################################## Keys Functions
  unsigned long long getPublicKey() {
    unsigned long long publicKey = 0;

    cout << "Enter a public key to encrypt: " << endl;
    cin >> publicKey;

    while (publicKey == 0 || euclidGCD(publicKey, this->phi) != 1) {
      cout << "Invalid public key, please enter another one: " << endl;
      cin.clear();
      cin.ignore(9, '\n');
      cin >> publicKey;
    }

    cin.clear();
    cin.ignore(9, '\n'); // cin.ignore(nCountOfChar, delim);

    return publicKey;
  }

  int getPrivateKey(int publicKey, int phi) {
    int x = 0;
    int y = 0;
    int g = gcdExtended(publicKey, phi, &x, &y);

    if (x < 0) x = phi + x;

    return x;
  }

  // ############################################################## Msg Functions

  vector<int> getMsg()
  {
    char message[256];
    int msgCount;
    int j = 0;

    cout << "Enter a message to encrypt: ";
    cin.getline(message, 256);
    msgCount = cin.gcount() - 1; //Ignore end of line character
    cout << "Message Size: " << msgCount << ". ";

    vector<int> BEARCATII(msgCount, -1);

    for(int i = 0; i < msgCount; i++)
    {
        if(message[i] == 32) //32 is ASCII for space
        {
            BEARCATII[j] = 0;
            j++;
        }
        else if((message[i] > 96) && (message[i] < 123))
        {
            BEARCATII[j] = int(message[i]) - 96; //Subtract 96 to turn ASCII alphabet into BEARCATII
            j++;
        }
        else
        {
            cout << "Invalid characters used, please try again." << endl;
            BEARCATII.clear(); // Clear vector
            return BEARCATII; // Return empty vector if error/invalid characters detected
        }
    }
    cout << "Message accepted." << endl;
    return BEARCATII;
  }

  string BCtoEng(vector<int> BEARCATII)
  {
    string raw_message;

    for(int i = 0; i < int(BEARCATII.size()); i++) // Iterate through vector converting BEARCATII back to ASCII representation
    {
        if(BEARCATII[i] == 0)
        {
            raw_message += ' '; // 0 represents 'space'
        }
        else
        {
            raw_message += char(BEARCATII[i] + 96); // Add 96 to adjust BEARCATII to ASCII
        }
    }
    return raw_message; // Return string rather than a C-Str for simplicity
  }

  // ############################################################## number converting functions

  int polyEval(vector<int> coef, int base = 27)
  {
    coef = this->msg_bc;
    int l = (int)coef.size();
    int indexFactor = l - 1;
    int even = 0;
    int odd = 0;

    //Corner check for l = 1 or 2
    if (l == 1) return coef.at(0);

    if (l == 2) return (coef.at(0) + coef.at(0) * base);

    //If l > 2, determine initial value for even & odd
    if (l % 2 == 0){
        odd = coef.at(0);
        even = coef.at(1);
    }
    else{
        odd = coef.at(1);
        even = coef.at(0);
    }

    //Polyn Calculation
    for(int i = 2; i < l; i++){
        int index = abs(i - indexFactor);
        if (index % 2 == 0) even = even * base * base + coef.at(i);
        else odd = odd * base * base + coef.at(i);
    }

    //multiply base for odd after loop
    odd *= base;
    return (even + odd);
  }

  vector<int> changeBase(int num, int base){
    vector<int> res;

    while (num > base){
        int r = num % base;
        num = (num - r) / base;
        res.insert (res.begin(), int(r));
    }
    res.insert (res.begin(), int(num));
    return res;
  }

  // ############################################################## Prime Test functions
  // modular exponentiation.
// returns (a^b) % n
  long modExp(long a, unsigned long b, long n)
  {
    long accumPowers = 1;
    a = a % n;

    while (b > 0)
    {
        if (b & 1) accumPowers = (accumPowers * a) % n;

        b = b >> 1;
        a = (a * a) % n;
    }
    return accumPowers;
  }

  int generatePrimeCandidate(int k) {
    if (k % 2 == 0) k = k + 1;

    while (true) {
        k = k + 2;
        bool prime = millerRabinWrapper(k, 40);
        if (prime == true) return k;
    }
  }

/*
 * step 1: find n - 1 = (2^k) m
 * step 2: choose a from 1 < a < n - 1
 * step 3: compute b0 = a^m (mod n), bi = (bi-1)^2
 */

  bool millerRabin(int n) {
    int nMinus1 = n - 1;

    // step 1
    int m = n - 1;
    int k = 0;

    while (m % 2 == 0) {
        m = m / 2;
        k = k + 1;
    }

    // step 2
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(1, n-1); // define the range

    int a = distr(eng);

    // step 3
    int b;
    b = modExp(a, m, n);
    if (b == 1 || b == nMinus1) return true;

    // iterate b after b0 up to k - 1 times
    for (int i = 0; i < k - 1; i ++) {
        b = modExp(b, 2, n);
        if (b == 1) return false;
        if (b == nMinus1) return true;
    }
    return false;
  }

  bool millerRabinWrapper(int n, int k) {
    for (int i = 0; i < k; i++) {
      if (!millerRabin(n)) return false;
    }
    return true;
  }

  // ############################################################## GCD
/***************************************************************
|Description: This function finds the greatest common divisor
|	      of the inputs a and b.
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
|Description: This function finds the greatest common divisor
|	      of the inputs a and b while finding values s and
|             t such that sa + tb = g where g is the gcd(a, b).
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

  int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
  }

  void report(){
    cout << "" << endl;
    cout << "------------- Final Output -------------" << endl;
    cout << "p -------> " << this->p << endl;
    cout << "q -------> " << this->q << endl;
    cout << "n -------> " << this->n << endl;
    cout << "M -------> " << this->BCtoEng(msg_bc) << endl;
    cout << "C -------> " << this->c << endl;
    cout << "P -------> " << this->msg_original << endl;

  }

};
