#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Structure to store book information
struct Book {
    string author;
    int year;
};

// Library class
class Library {
private:
    map<string, Book> books;                // title -> book info
    vector<string> availableBooks;          // list of available books
    map<string, queue<string> > waitingList; // waiting list per book

public:
    // Add a book
    void addBook(string title, string author, int year) {
        books[title] = Book();
        books[title].author = author;
        books[title].year = year;
        availableBooks.push_back(title);
        cout << "Book \"" << title << "\" added successfully.\n";
    }

    // Display available books
    void showAvailableBooks() {
        cout << "\nAvailable Books:\n";
        if (availableBooks.empty()) {
            cout << "No books available.\n";
            return;
        }
        for (vector<string>::iterator it = availableBooks.begin(); it != availableBooks.end(); ++it) {
            cout << "- " << *it << endl;
        }
    }

    // Borrow a book
    void borrowBook(string title, string user) {
        // Check if book exists
        if (books.find(title) == books.end()) {
            cout << "Book \"" << title << "\" does not exist in library.\n";
            return;
        }

        // Check if book is available
        for (vector<string>::iterator it = availableBooks.begin(); it != availableBooks.end(); ++it) {
            if (*it == title) {
                availableBooks.erase(it);
                cout << user << " borrowed \"" << title << "\" successfully.\n";
                return;
            }
        }

        // Book not available ? add to waiting list
        waitingList[title].push(user);
        cout << "Book \"" << title << "\" is not available. " << user << " added to waiting list.\n";
    }

    // Return a book
    void returnBook(string title) {
        // Check if book exists
        if (books.find(title) == books.end()) {
            cout << "Book \"" << title << "\" does not exist in library.\n";
            return;
        }

        // If someone is waiting for the book, assign it
        if (!waitingList[title].empty()) {
            string nextUser = waitingList[title].front();
            waitingList[title].pop();
            cout << "Book \"" << title << "\" assigned to " << nextUser << " from waiting list.\n";
        } else {
            // Otherwise, add it back to available books
            availableBooks.push_back(title);
            cout << "Book \"" << title << "\" returned and is now available.\n";
        }
    }
};

// Main function
int main() {
    Library lib;

    // Adding books
    lib.addBook("C++ Programming", "Bjarne Stroustrup", 2013);
    lib.addBook("Data Structures", "Mark Allen Weiss", 2011);

    lib.showAvailableBooks();

    // Borrowing books
    lib.borrowBook("C++ Programming", "Ali");
    lib.borrowBook("C++ Programming", "Ahmed"); // Goes to waiting list

    // Returning books
    lib.returnBook("C++ Programming"); // Goes to Ahmed from waiting list

    lib.showAvailableBooks();

    // Test non-existing book
    lib.borrowBook("Java Programming", "Sara");
    lib.returnBook("Java Programming");

    return 0;
}

