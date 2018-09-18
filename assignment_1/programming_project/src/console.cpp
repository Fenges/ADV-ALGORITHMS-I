#include "../include/headers.hpp"

unsigned long long getPublicKey(int phi) {
    unsigned long long publicKey = 0;

    cout << "Enter a public key to encrypt: " << endl;
    cin >> publicKey;


    while (publicKey == 0 || euclidGCD(publicKey, phi) != 1) {
        cout << "Invalid public key, please reenter." << endl;
        cin.clear();
        cin.ignore(9, '\n');
        cin >> publicKey;
    }

    cin.clear();
    cin.ignore(9, '\n');

    return publicKey;
}

int getPrivateKey(int publicKey, int phi) {
    int x = 0;
    int y = 0;
    int g = gcdExtended(publicKey, phi, &x, &y);
    if (x < 0) x = phi + x;
    return x;
}
