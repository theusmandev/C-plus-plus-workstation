#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {
    string input, word;
    set<string> uniqueWords;

    cout << "Enter a string: ";
    getline(cin, input);

    // Split string into words
    stringstream ss(input);
    while (ss >> word) {
        uniqueWords.insert(word);
    }

    // Display unique words
    cout << "\nUnique words are:\n";
    for (set<string>::iterator it = uniqueWords.begin(); it != uniqueWords.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}

