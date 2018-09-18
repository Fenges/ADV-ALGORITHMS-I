#include "../include/headers.hpp"

std::vector<int> getMsg()
{
    char message[256];
    int msgCount;
    int j = 0;

    std::cout << "Enter a message to encrypt: ";
    std::cin.getline(message, 256);
    msgCount = std::cin.gcount() - 1; //Ignore end of line character
    std::cout << "Message Size: " << msgCount << ". ";

    std::vector<int> BEARCATII(msgCount, -1);

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
            std::cout << "Invalid characters used, please try again." << std::endl;
            BEARCATII.clear(); // Clear vector
            return BEARCATII; // Return empty vector if error/invalid characters detected
        }
    }
    std::cout << "Message accepted." << std::endl;
    return BEARCATII;
}

std::string BCtoEng(std::vector<int> BEARCATII)
{
    char raw_message[BEARCATII.size()];

    for(int i = 0; i < int(BEARCATII.size()); i++) // Iterate through vector converting BEARCATII back to ASCII representation
    {
        if(BEARCATII[i] == 0)
        {
            raw_message[i] = ' '; // 0 represents 'space'
        }
        else
        {
            raw_message[i] = char(BEARCATII[i] + 95); // Add 95 to adjust BEARCATII to ASCII
        }
    }
    return string(raw_message); // Return string rather than a C-Str for simplicity
}
