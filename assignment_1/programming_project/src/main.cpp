#include <string>
#include <tuple>
#include <iostream>
#include "./RSA.hpp"

using namespace std;

#define BASE 27

int main()
{
  // 1) Get two prime numbers
  RSA rsa = RSA();
  rsa.set_p(rsa.generatePrimeCandidate(2000));
  rsa.set_q(rsa.generatePrimeCandidate(3000));
  rsa.set_phi();

  // 2) Get public key e
  rsa.set_publicKey();

  // 3) Get message in BEARCATII
  rsa.set_msg_bc();

  // 4) Convert message from list of numbers of base 27 to a single number of decimal
  rsa.set_msg_decimal();

  // 5) Encrypt message
  rsa.set_n();
  rsa.set_c();

  // 6) Decrypt message (get privateKey)
  rsa.set_privateKey();
  rsa.set_m();

  // 7) Change base back to 27
  rsa.set_msg_base27();

  // 8) 27 to Eng
  rsa.set_msg_original();

  // 9) Report
  rsa.report();

  return 0;
}
