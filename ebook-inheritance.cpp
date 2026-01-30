#include <iostream>
#include <string>
using namespace std;

// Base class
class Book {
protected:
    string title;
    string author;

public:
    // Function to input book details
    void inputBookDetails() {
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
    }

    // Function to display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

// Derived class
class EBook : public Book {
private:
    float fileSize;  // in MB
    string format;   // PDF, EPUB, etc.

public:
    // Function to input eBook details
    void inputEBookDetails() {
        inputBookDetails(); // input base class data
        cout << "Enter file size (MB): ";
        cin >> fileSize;
        cin.ignore(); // ignore newline
        cout << "Enter format (PDF, EPUB, etc.): ";
        getline(cin, format);
    }

    // Function to display eBook details
    void displayEBookDetails() {
        displayBookDetails(); // display base class data
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }
};

int main() {
    EBook myEBook;

    cout << "--- Input EBook Details ---\n";
    myEBook.inputEBookDetails();

    cout << "\n--- EBook Details ---\n";
    myEBook.displayEBookDetails();

    return 0;
}

