#include <iostream>
#include "headers.hpp"
#include <tuple>

int main()
{
    cout << "#########################################################" << endl;
    cout << "Miller-Rabin Primility Test: " << endl;
    int k = 4;  // Number of iterations

    for (int n = 1; n < 100; n++)
        if (isPrime(n, k))
            cout << n << " ";

    cout << "#########################################################" << endl;
    cout << "Euclid GCD: " << endl;
    cout << "gcd(23, 36) = " << euclidGcd(24, 36) << endl;
    
    cout << "#########################################################" << endl;
    cout << "Extended Euclid GCD: ";
    tuple<int, int, int> extendGcdRes = extendGcd(56700, 119070, 0, 0, 0);
    cout << get<0>(extendGcdRes) << " ";
    cout << get<1>(extendGcdRes) << " ";
    cout << get<2>(extendGcdRes) << " ";
    cout << endl;

    cout << "#########################################################" << endl;
    cout << "Number Convert - toDecimal: " << endl;
    cout << "toDecimal({20, 5, 19, 20}, 27) = " << toDecimal({20, 5, 19, 20}, 27) << endl;

    cout << "#########################################################" << endl;
    cout << "Number Convert - toNum: " << endl;
    vector<int> convertedNum = toNum(397838, 27);
    cout << "toNum(397838, 27) = ";
    for(int i = 0; i < convertedNum.size(); i++)
        cout << convertedNum.at(i) << " ";
    cout << endl;

    cout << "#########################################################" << endl;
    return 0;
}
