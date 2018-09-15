/* headers_hpp */
#ifndef headers_hpp
#define headers_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int euclidGcd(int a, int b);
vector<int> extendEuclidGcd(int a, int b, int g, int x, int y);
bool isPrime(long n, long k);
bool isCoPrime(int p, int q, int e);
int polyEval(std::vector<int> num, int base);
vector<int> changeBase(int num, int base);

unsigned long long modularExponentiation(int x, unsigned long long y, int p);

// Jianfeng's version
int gcdExtended(int a, int b, int *x, int *y);
bool millerRabinWrapper(int n, int k);
int generatePrimeCandidate(int k);

#endif
