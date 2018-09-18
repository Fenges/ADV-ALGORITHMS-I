#include "../include/headers.hpp"

int getPublicKey(int phi) {
    int publicKey = 0;

    cout << "Enter a public key to encrypt: " << endl;
    cin >> publicKey;


    while (publicKey == 0 || euclidGCD(publicKey, phi) != 1) {
        cout << "Invalid public key, please reenter." << endl;
        cin.clear();
        cin.ignore(1);
        cin >> publicKey;
    }

    return publicKey;
}
