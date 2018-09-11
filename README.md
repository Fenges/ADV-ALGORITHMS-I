# ADV-ALGORITHMS-I

The doc is under `assignment_1/Assignment 1.docx`.

## RSA Workflows:
##### 1) Get 2 Random Positive Numbers.
>- getRandInt()

##### 2) Check the primality of p & q with MillerRabinPrimeTest() for primality.
>- isPrime()

##### 3) Prompt User for public key **e**
>- getPublicKey();

##### 4) Check for CoPrime
>- extendEuclidGcd()
>- euclidGcd()

##### 4.a) If pass the CoPrime test, proceed. Otherwise back to step 3 and repeat.

##### 5) Prompt User for message
>- getMsg()

##### 6) Convert message into a list of integers by using BearCatASCII.
>- engToBearCatAscii()

##### 7) Covert list of integers (27th base) to a single number (decimal)
>- polyEval()

##### 8) Encrypt single number (decimal) 
>- rsaEncrypt();

##### 8) Decrypt the encrypted message (a number)
>- rsaDecrypt();

##### 9) Convert decrypted message into a list of integers
>- changeBase();

##### 10) Convert list of integers into English by using BearCatASCII.
>- bearCatAsciiToEng()

##### 11) Output all result



## Method List:

>- int getRandInt();

>- bool isPrime(int n, int k);

>- int getPublicKey();

>- int euclidGcd(int e, int phiN);

>- tuple<int, int, int> extendEuclidGcd(int a, int b, int g, int x, int y);

>- string getMsg();

>- list<int> engToBearCatAscii(string msg);

>- int polyEval(list<int> bca, int base);

>- int rsaEncrypt(int polyVal);

>- int rsaDecrypt(int rsaEnc);

>- list<int> changeBase(int rsaDec, int base);

>- string bearCatAsciiToEng(list<int> bca);

## Alex's List:
>- ...

>> ...

>- ...

>> ...

## Jianfeng's List:
>- ...

>> ...

>- ...

>> ...

## Nathan's List:
>- ...

>> ...

>- ...

>> ...

## Xin's List:
>- bool isPrime(int n, int k); 

>> Implemented by using miller-rabin, if no other prime test is used to replace this implementation, it can be considered as DONE

>- int euclidGcd(int e, int phiN);

>> phiN = (p-1)*(q-1), and it returns the GCD(e, phiN) to check coprime.

>- tuple<int, int, int> extendEuclidGcd(int a, int b, int g, int x, int y);

>> this is implemented based on Prof's psudo code, but not sure if this is needed for RSA implementation, since euclidGcd() works okay for coprime check ( euclidGcd() ?= 1)

>- int polyEval(list<int> bca, int base);

>> Implemented as convert list of integers to a single number

>- list<int> changeBase(int rsaDec, int base);

>> Implemented as convert a single number to a list of integer on ANY base.
