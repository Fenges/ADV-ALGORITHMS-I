#include "../include/headers.hpp"

vector<int> getMsg()
{
    char message[256];
    int msgCount;
    int j = 0;

    cout << "Enter a message to encrypt: ";
    cin.getline(message, 256);
    msgCount = cin.gcount() - 1; //Ignore end of line character
    cout << "Message Size: " << msgCount << ". ";

    vector<int> BEARCATII(msgCount, -1);

    for(int i = 0; i < msgCount; i++)
    {
        if(message[i] == 32) //32 is ASCII for space
        {
            BEARCATII[j] = 0;
            j++;
        }
        else if((message[i] > 96) && (message[i] < 123))
        {
            BEARCATII[j] = int(message[i]) - 96; //Subtract 96 to turn ASCII alphabet into BEARCATII
            j++;
        }
        else
        {
            cout << "Invalid characters used, please try again." << endl;
            BEARCATII.clear(); // Clear vector
            return BEARCATII; // Return empty vector if error/invalid characters detected
        }
    }
    cout << "Message accepted." << endl;
    return BEARCATII;
}

string BCtoEng(vector<int> BEARCATII)
{
    string raw_message;

    for(int i = 0; i < int(BEARCATII.size()); i++) // Iterate through vector converting BEARCATII back to ASCII representation
    {
        if(BEARCATII[i] == 0)
        {
            raw_message += ' '; // 0 represents 'space'
        }
        else
        {
            raw_message += char(BEARCATII[i] + 96); // Add 96 to adjust BEARCATII to ASCII
        }
    }
    return raw_message; // Return string rather than a C-Str for simplicity
}

