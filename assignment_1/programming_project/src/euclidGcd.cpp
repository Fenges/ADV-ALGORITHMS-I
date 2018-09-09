#include "headers.hpp"

// C++ Euclid GCD
int euclidGcd(int a, int b)
{
    while (b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}