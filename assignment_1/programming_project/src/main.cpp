#include <string>
#include <tuple>
#include <iostream>
#include "../include/headers.hpp"

using namespace std;

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
    tuple<int, int, int> extendGcdRes = extendEuclidGcd(56700, 119070, 0, 0, 0);
    cout << get<0>(extendGcdRes) << " ";
    cout << get<1>(extendGcdRes) << " ";
    cout << get<2>(extendGcdRes) << " ";
    cout << endl;

    cout << "#########################################################" << endl;
    cout << "Number Convert - polyEval: " << endl;
    cout << "polyEval({20, 5, 19, 20}, 27) = " << polyEval({20, 5, 19, 20}, 27) << endl;

    cout << "#########################################################" << endl;
    cout << "Number Convert - changeBase: " << endl;
    vector<int> convertedNum = changeBase(397838, 27);
    cout << "changeBase(397838, 27) = ";
    for(int i = 0; i < convertedNum.size(); i++)
        cout << convertedNum.at(i) << " ";
    cout << endl;

    cout << "#########################################################" << endl;
    return 0;
}
