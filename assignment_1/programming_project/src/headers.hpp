/* headers_hpp */
#ifndef headers_hpp
#define headers_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

int euclidGcd(int a, int b);
std::tuple<int, int, int> extendGcd(int a, int b, int g, int x, int y);
bool isPrime(int n, int k);
bool isCoPrime(int p, int q, int e);
int toDecimal(std::vector<int> num, int base);
std::vector<int> toNum(int num, int base);

#endif
