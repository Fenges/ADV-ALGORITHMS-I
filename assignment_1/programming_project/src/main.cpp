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

    cout << ">> p: " << p << ",    q: " << q << endl;
    // output phi(n) = (p-1)(q-1)
    int phi = (p-1)*(q-1);
    cout << ">> phi(n): " << phi << endl;

    // 2) Get public key e
    unsigned long long publicKey = getPublicKey(phi);

    // 3) Get message in BEARCATII
    vector<int> msg_bc = getMsg();

    // 4) Convert message from list of numbers of base 27 to a single number of decimal
    //int messageDecimal = polyEval(msg_bc, 27);
    int msg_decimal = polyEval(msg_bc, 27);
    cout << ">> Message in decimal: " << msg_decimal << endl;

    // 5) Encrypt message
    int n = p*q;
    int c = modExp(msg_decimal, publicKey, n);
    cout << ">> Encrypted message: " << c << endl;

    // 6) Decrypt message (get privateKey)
    int privateKey = getPrivateKey(publicKey, phi);
    int m = modExp(c, privateKey, n);
    cout << ">> Decrypted message: " << m << endl;

    // 7) Change base back to 27
    vector<int> msg_base27 = changeBase(m, 27);

    // 8) 27 to Eng
    string msg_original = BCtoEng(msg_base27);
    cout << msg_original << endl;

    // 9) Output all
    cout << "" << endl;
    cout << "------------- Final Output -------------" << endl;
    cout << "p -------> " << p << endl;
    cout << "q -------> " << q << endl;
    cout << "n -------> " << n << endl;
    cout << "M -------> " << BCtoEng(msg_bc) << endl;
    cout << "C -------> " << c << endl;
    cout << "P -------> " << msg_original << endl;

  return 0;
}
