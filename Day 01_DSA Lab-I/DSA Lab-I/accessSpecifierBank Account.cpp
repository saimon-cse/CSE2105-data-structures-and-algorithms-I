#include <iostream>

class BankAccount {
private:
    int balance;  // Private data member

public:
    // Constructor to initialize balance
    BankAccount(int initialBalance) : balance(initialBalance) {}

    // Public member function to deposit money
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << " units. New balance: " << balance << std::endl;
        }
    }

    // Public member function to withdraw money
    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn " << amount << " units. New balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    // Public member function to get balance (read-only)
    int getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(1000);  // Create a bank account with initial balance of 1000 units

    // Try to access the balance directly (which is private)
    // int currentBalance = account.balance;  // Error: 'int BankAccount::balance' is private within this context

    // Deposit and withdraw money using public member functions
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(1500);  // Attempt to withdraw more than the balance

    // Access the balance using the public member function
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    return 0;
}
