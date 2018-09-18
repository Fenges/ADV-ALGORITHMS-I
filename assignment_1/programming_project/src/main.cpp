#include <string>
#include <tuple>
#include <iostream>
#include "../include/headers.hpp"

using namespace std;

#define BASE 27

int main()
{
    // 1) Get two prime numbers
    int p = generatePrimeCandidate(2000);
    int q = generatePrimeCandidate(3000);

    cout << "p: " << p << "; q: " << q << endl;
    // output phi(n) = (p-1)(q-1)
    int phi = (p-1)*(q-1);
    cout << "phi(n): " << phi << endl;

    // 2) Get public key e
    unsigned long long publicKey = getPublicKey(phi);

    // 3) Get message
    vector<int> message_BEARCATII = getMsg();

    // 4) Convert message to base 27
    int messageDecimal = polyEval(message_BEARCATII, 27);
    cout << "message in decimal: " << messageDecimal << endl;

    // 5) Encrypt message
    int n = p*q;
    unsigned long long c = modularExponentiation(messageDecimal, publicKey, n);
    cout << "encrypted message: " << c << endl;

    // 6 Decrypt message
    int privateKey = getPrivateKey(publicKey, phi);
    cout << "phi: " << phi << endl;
    cout << "public key: " << publicKey << endl;
    cout << "private key: " << privateKey << endl;
    unsigned long long m = modularExponentiation(c, privateKey, n);
    cout << "decrypted message: " << m << endl;

//  cout << "######################################################### Euclid GCD:" << endl;
//  cout << "gcd(23, 36) = " << euclidGcd(24, 36) << endl;
//
//  cout << "######################################################### Extended Euclid GCD: " << endl;
//  vector<int> extendGcdRes = extendEuclidGcd(56700, 119070, 0, 0, 0);
//  cout << extendGcdRes.at(0) << " ";
//  cout << extendGcdRes.at(1) << " ";
//  cout << extendGcdRes.at(2) << " ";
//  cout << endl;
//
//  cout << "######################################################### polyEval: " << endl;
//  // this will be set to the message array
//  int arr[] = {20, 5, 19, 20};
//  // get size of array -> sizeof(arr) = 4 * 4 = 16 bytes / sizeof(int) = 4 bytes = 4 values
//  int size = (sizeof(arr)) / sizeof(int)) - 1;
//  cout << "polyEval(arr, size, BASE) = " << polyEval(arr, size, BASE) << endl;
//
//  cout << "######################################################### changeBase:" << endl;
//  vector<int> convertedNum = changeBase(397838, BASE);
//  cout << "changeBase(397838, BASE) = ";
//  for(int i = 0; i < convertedNum.size(); i++)
//    cout << convertedNum.at(i) << " ";
//  cout << endl;
//
//  cout << "#########################################################" << endl;
  return 0;
}
