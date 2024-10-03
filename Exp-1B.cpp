#include <iostream>
using namespace std;

double accountBalance=0.0;  
double account_id;

void checkBalance() {
    cout << "Current Balance: " << accountBalance << endl;
}

void deposit(double amount) {
    if (amount > 0) {
        accountBalance += amount;
        cout << "Deposited: " << amount << endl;
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

void withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount!" << endl;
    } else if (accountBalance - amount < 500) {
        cout << "Insufficient funds! Minimum balance of $500 must be maintained." << endl;
    } else if (amount > accountBalance) {
        cout << "Insufficient funds!" << endl;
    } else {
        accountBalance -= amount;
        cout << "Withdrew: $" << amount << endl;
    }
}

int main() {
    int option;
    char choice = 'y';

    do {
        cout << "\nBank Management System Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> option;
        
        switch (option) {
            case 1:
                checkBalance();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(amount);
                checkBalance();
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(amount);
                checkBalance();
                break;
            }
            case 4:
                cout << "Exiting the system.\n";
                choice = 'n'; 
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        
        if (option != 4) {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
