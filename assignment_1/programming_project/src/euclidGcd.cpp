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

tuple<int, int, int> extendGcd(int a, int b, int g, int x, int y)
{
    if (b == 0){
        return make_tuple(a, 1, 0);
    }
    
    int r = a%b;
    int q = a/b;
    
    //Recursive call
    tuple<int, int, int> res = extendGcd(b, r, g, x, y);
    g = get<0>(res);
    x = get<1>(res);
    y = get<2>(res);
    
    int xTemp = x;
    x = y;
    y = xTemp - y*q;
    
    return make_tuple(g, x, y);
}
