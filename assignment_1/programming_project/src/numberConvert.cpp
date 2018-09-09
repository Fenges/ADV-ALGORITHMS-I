#include "headers.hpp"

// C++ Euclid GCD
int toDecimal(std::vector<int> num, int base)
{
    int l = (int)num.size();
    int indexFactor = l - 1;
    int even = 0;
    int odd = 0;
    
    //Corner check for l = 1 or 2
    if (l == 1){
        return num.at(0);
    }
    
    if (l == 2){
        return (num.at(0) + num.at(0) * base);
    }
    
    //If l > 2, determine initial value for even & odd
    if (l % 2 == 0){
        odd = num.at(0);
        even = num.at(1);
    }
    else{
        odd = num.at(1);
        even = num.at(0);
    }
    
    //Polyn Calculation
    for(int i = 2; i < l; i++){
        int index = abs(i - indexFactor);
        if (index % 2 == 0){
            even = even * base * base + num.at(i);
        }
        else{
            odd = odd * base * base + num.at(i);
        }
    }
    
    //multiply base for odd after loop
    odd *= base;
    return (even + odd);
}

std::vector<int> toNum(int num, int base){
    std::vector<int> res = {};

    while (num > base){
        int r = num % base;
        num = (num - r) / base;
        res.insert (res.begin(), int(r));
    }
    res.insert (res.begin(), int(num));
    return res;
}

