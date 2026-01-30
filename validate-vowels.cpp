#include <iostream>
#include <string>
using namespace std;

// Method that checks vowels
void checkVowels(string str)
{
    bool hasVowel = false;

    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || 
            ch == 'o' || ch == 'u')
        {
            hasVowel = true;
            break;
        }
    }

    // If no vowel found, throw exception
    if (!hasVowel)
    {
        throw "Error: String has no vowels!";
    }

    cout << "Valid string. It contains vowel(s)." << endl;
}

int main()
{
    string input;

    try
    {
        cout << "Enter a string: ";
        cin >> input;

        checkVowels(input);
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        cout << "Program terminated gracefully." << endl;
    }

    return 0;
}

