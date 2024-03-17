#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    string username;
    string password;
    double balance;

public:
    Account() {
        balance = 1000.0;
    }

    void signUp() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Account created successfully!\n";
    }

    bool logIn(string uname, string pwd) {
        if (uname == username && pwd == password) {
            cout << "Logged in successfully!\n";
            return true;
        } else {
            cout << "Incorrect username or password.\n";
            return false;
        }
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    void viewAccount() {
        cout << "Username: " << username << endl;
        cout << "Balance: $" << balance << endl;
    }

    void applyForLoan() {
        double loanAmount;
        cout << "Enter loan amount: $";
        cin >> loanAmount;
        balance += loanAmount;
        cout << "Loan applied successfully!\n";
    }
};

int main() {
    Account userAccount;
    bool loggedIn = false;
    int choice;

    while (true) {
        cout << "1. Log in\n2. Sign up\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string uname, pwd;
                cout << "Enter username: ";
                cin >> uname;
                cout << "Enter password: ";
                cin >> pwd;
                loggedIn = userAccount.logIn(uname, pwd);
                break;
            }
            case 2:
                userAccount.signUp();
                loggedIn = true;
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                continue;
        }

        if (loggedIn) {
            while (true) {
                cout << "\n1. Check Balance\n2. View Account\n3. Deposit\n4. Withdraw\n5. Apply for Loan\n6. Log Out\nEnter choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Your balance is: $" << userAccount.getBalance() << endl;
                        break;
                    case 2:
                        userAccount.viewAccount();
                        break;
                    case 3: {
                        double amount;
                        cout << "Enter amount to deposit: $";
                        cin >> amount;
                        userAccount.deposit(amount);
                        break;
                    }
                    case 4: {
                        double amount;
                        cout << "Enter amount to withdraw: $";
                        cin >> amount;
                        userAccount.withdraw(amount);
                        break;
                    }
                    case 5:
                        userAccount.applyForLoan();
                        break;
                    case 6:
                        loggedIn = false;
                        cout << "Logged out successfully!\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        continue;
                }
            }
        }
    }

    return 0;
}
