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
    int c = power(messageDecimal, publicKey, n);
    cout << "encrypted message: " << c << endl;

    // 6) Decrypt message
    int privateKey = getPrivateKey(publicKey, phi);
    int m = power(c, privateKey, n);
    cout << "decrypted message: " << m << endl;

    // 7) Change base back to 27
    vector<int> messageBase27 = changeBase(m, 27);

    // 8) 27 to Eng
    string originalMessage = BCtoEng(messageBase27);
    cout << originalMessage << endl;

    // 9) Output all
    cout << "-------------final output -------------" << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "n: " << n << endl;
    cout << "M: " << BCtoEng(message_BEARCATII) << endl;
    cout << "C: " << c << endl;
    cout << "P: " << originalMessage << endl;

  return 0;
}
