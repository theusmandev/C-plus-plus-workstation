#include <iostream>
#include <string>
using namespace std;

// Base class
class User {
private:
    string username;
    string email;

public:
    // Setter for username
    void setUsername(const string& name) {
        username = name;
    }

    // Getter for username
    string getUsername() const {
        return username;
    }

    // Setter for email
    void setEmail(const string& mail) {
        email = mail;
    }

    // Getter for email
    string getEmail() const {
        return email;
    }
};

// Derived class: Admin
class Admin : public User {
public:
    void accessControlPanel() {
        cout << getUsername() << " is accessing the Admin Control Panel.\n";
    }
};

// Derived class: Member
class Member : public User {
public:
    void browseContent() {
        cout << getUsername() << " is browsing content.\n";
    }
};

int main() {
    // Create Admin object
    Admin adminUser;
    string inputName, inputEmail;

    cout << "--- Admin User ---\n";
    cout << "Enter username: ";
    getline(cin, inputName);
    adminUser.setUsername(inputName);

    cout << "Enter email: ";
    getline(cin, inputEmail);
    adminUser.setEmail(inputEmail);

    cout << "\nAdmin Details:\n";
    cout << "Username: " << adminUser.getUsername() << endl;
    cout << "Email: " << adminUser.getEmail() << endl;
    adminUser.accessControlPanel();

    // Create Member object
    Member memberUser;

    cout << "\n--- Member User ---\n";
    cout << "Enter username: ";
    getline(cin, inputName);
    memberUser.setUsername(inputName);

    cout << "Enter email: ";
    getline(cin, inputEmail);
    memberUser.setEmail(inputEmail);

    cout << "\nMember Details:\n";
    cout << "Username: " << memberUser.getUsername() << endl;
    cout << "Email: " << memberUser.getEmail() << endl;
    memberUser.browseContent();

    return 0;
}

