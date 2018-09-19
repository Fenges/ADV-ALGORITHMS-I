#include "RSA.h"

RSA::int getPrivateKey(int, int);
RSA::unsigned long long getPublicKey(int);

RSA::string BCtoEng(vector<int>);
RSA::vector<int> getMsg();

RSA::int generatePrimeCandidate(int k);

RSA::bool millerRabinWrapper(int, int);
RSA::bool millerRabin(int);

RSA::int polyEval(int[], int, int);

RSA::long modExp(long, unsigned long, long);
RSA::unsigned long long modularExponentiation(int, unsigned long long, int);


RSA::int euclidGCD(int, int);
RSA::vector<int> extendEuclidGCD(int, int, int, int, int);
RSA::int gcdExtended(int, int, int*, int*);
