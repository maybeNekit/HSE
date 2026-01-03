#include <iostream>

struct BankAccount {
    int balance;
    int pin;

    BankAccount(int initial_balance, int initial_pin)
        : balance(initial_balance), pin(initial_pin) {}

    void deposit(int amount, int input_pin) {
        if (input_pin == pin) {
            balance += amount;
            std::cout << balance << '\n';
        } else {
            std::cout << "ERROR" << '\n';
        }
    }

    void withdrawal(int amount, int input_pin) {
        if (input_pin == pin && balance >= amount) {
            balance -= amount;
            std::cout << balance << '\n';
        } else {
            std::cout << "ERROR" << '\n';
        }
    }

    void getBalance(int input_pin) {
        if (input_pin == pin) {
            std::cout << balance << '\n';
        } else {
            std::cout << "ERROR" << '\n';
        }
    }

    void changePIN(int old_pin, int new_pin) {
        if (old_pin == pin && new_pin >= 1000 && new_pin <= 9999 && old_pin != new_pin) {
            pin = new_pin;
            std::cout << "SUCCESS" << '\n';
        } else {
            std::cout << "ERROR" << '\n';
        }
    }
};

int main() {
    int initial_balance, initial_pin;
    std::cin >> initial_balance >> initial_pin;

    BankAccount account(initial_balance, initial_pin);

    std::string operation;
    while (std::cin >> operation) {
        if (operation == "DEPOSIT") {
            int amount, pin;
            std::cin >> amount >> pin;
            account.deposit(amount, pin);
        } else if (operation == "WITHDRAWAL") {
            int amount, pin;
            std::cin >> amount >> pin;
            account.withdrawal(amount, pin);
        } else if (operation == "GET_BALANCE") {
            int pin;
            std::cin >> pin;
            account.getBalance(pin);
        } else if (operation == "CHANGE_PIN") {
            int old_pin, new_pin;
            std::cin >> old_pin >> new_pin;
            account.changePIN(old_pin, new_pin);
        } else if (operation == "EXIT") {
            break;
        }
    }

    return 0;
}
