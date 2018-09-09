#include <iostream>
#include "headers.hpp"

using namespace std;

int main()
{
    std::cout << "#########################################################" << std::endl;
    std::cout << "Miller-Rabin Primility Test: " << std::endl;
    int k = 4;  // Number of iterations

    for (int n = 1; n < 100; n++)
        if (isPrime(n, k))
            std::cout << n << " ";

    std::cout << "#########################################################" << std::endl;
    std::cout << "Euclid GCD: " << std::endl;
    std::cout << "gcd(23, 36) = " << euclidGcd(24, 36) << std::endl;
    
    std::cout << "#########################################################" << std::endl;
    std::cout << "Number Convert - toDecimal: " << std::endl;
    std::cout << "toDecimal({20, 5, 19, 20}, 27) = " << toDecimal({20, 5, 19, 20}, 27) << std::endl;

    std::cout << "#########################################################" << std::endl;
    std::cout << "Number Convert - toNum: " << std::endl;
    std::vector<int> convertedNum = toNum(397838, 27);
    std::cout << "toNum(397838, 27) = ";
    for(int i = 0; i < convertedNum.size(); i++)
        std::cout << convertedNum.at(i) << " ";
    std::cout << std::endl;
    
    std::cout << "#########################################################" << std::endl;
    return 0;
}
