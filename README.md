# ADV-ALGORITHMS-I

The doc is under `assignment_1/Assignment 1.docx`.

## Prerequisites

- gpp compiler

## Running the code

### Running C++ code locally

Change direcotry to `assignment_1/programming_project`. To complie all files and generate the executable, issue the command 
    
    make
    
The .o files will be generated under `build/src/`, and the executable a.out will be generated under `build/`. To run the executable, change directory to `build/` and issue the command
    
    ./a.out
    

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
>- getMsg() //I plan to combine getMsg and the conversion to BearCatASCII into one function

##### 6) Convert message into a list of integers by using BearCatASCII.
>- engToBearCatAscii() //I plan to combine getMsg and the conversion to BearCatASCII into one function

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
>- string getMsg();

>- list<int> engToBearCatAscii(string msg);

>- string bearCatAsciiToEng(list<int> bca);
    
>- changeBase(); //I might be able to do this once I have an idea what this function is doing, could be wrapped up with BearCat to English function

## Jianfeng's List:
>- ...

>> ...

>- ...

>> ...

## Nathan's List:
>- extendedEuclidGCD -- DONE

>- euclidGCD -- DONE

>- hornerEval (polyEval) -- DONE

>> ...

## Xin's List:
>- bool isPrime(int n, int k); 

>> Implemented by using miller-rabin, if no other prime test is used to replace this implementation, it can be considered as DONE

>- list<int> changeBase(int rsaDec, int base);

>> Implemented as convert a single number to a list of integer on ANY base.
