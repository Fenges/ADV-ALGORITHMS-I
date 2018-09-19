// need to decide what is public and what is private
// eliminate duplicates

class RSA {
  private:
  
  public:
    int getPrivateKey(int, int);
    unsigned long long getPublicKey(int);

    string BCtoEng(vector<int>);
    vector<int> getMsg();

    int generatePrimeCandidate(int k);

    bool millerRabinWrapper(int, int);
    bool millerRabin(int);

    int polyEval(int[], int, int);

    long modExp(long, unsigned long, long);
    unsigned long long modularExponentiation(int, unsigned long long, int);


    int euclidGCD(int, int);
    vector<int> extendEuclidGCD(int, int, int, int, int);
    int gcdExtended(int, int, int*, int*);
};
