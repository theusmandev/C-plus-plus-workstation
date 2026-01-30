#include <iostream>
#include <string>
using namespace std;

// Template class for Account
template <typename T>
class Account {
private:
    string accountHolder;
    T balance;    // Balance can be in USD, EUR, etc.

public:
    // Constructor
    Account(string name, T initialBalance) : accountHolder(name), balance(initialBalance) {}

    // Display account info
    void display() const {
        cout << "Account Holder: " << accountHolder << ", Balance: " << balance << endl;
    }

    // Declare BankManager as friend
    template <typename U>
    friend class BankManager;
};

// BankManager class
template <typename T>
class BankManager {
public:
    // Deposit money into any account
    void deposit(Account<T>& acc, T amount) {
        acc.balance += amount;
        cout << amount << " deposited successfully.\n";
    }

    // Withdraw money from any account
    void withdraw(Account<T>& acc, T amount) {
        if (amount > acc.balance) {
            cout << "Insufficient balance!\n";
        } else {
            acc.balance -= amount;
            cout << amount << " withdrawn successfully.\n";
        }
    }

    // Check balance
    void checkBalance(Account<T>& acc) {
        cout << "Current balance: " << acc.balance << endl;
    }
};

int main() {
    // Create accounts in different currencies
    Account<double> acc1("Alice", 1000.50); // USD
    Account<int> acc2("Bob", 500);          // EUR (integer amount)

    BankManager<double> managerUSD;
    BankManager<int> managerEUR;

    cout << "--- Initial Balances ---\n";
    acc1.display();
    acc2.display();

    // Operations on USD account
    managerUSD.deposit(acc1, 200.75);
    managerUSD.withdraw(acc1, 50.25);
    managerUSD.checkBalance(acc1);

    cout << "\n--- EUR Account ---\n";
    managerEUR.deposit(acc2, 100);
    managerEUR.withdraw(acc2, 700); // insufficient balance
    managerEUR.checkBalance(acc2);

    return 0;
}

