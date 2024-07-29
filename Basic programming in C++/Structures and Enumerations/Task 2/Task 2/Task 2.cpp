#include <iostream>
#include <string>

struct BankAccount {
	int accountNumber;
	std::string name;
	int balance;
};

void change_blance(BankAccount &account, int new_balance) {
	account.balance = new_balance;
}

int main()
{
	BankAccount account;
	std::cout << "Enter your bank account: ";
	std::cin >> account.accountNumber;
	std::cout << "Enter your name: ";
	std::cin >> account.name;
	std::cout << "Enter your balance: ";
	std::cin >> account.balance;
	std::cout << "Enter a new balance: ";
	int new_balance;
	std::cin >> new_balance;
	change_blance(account, new_balance);
	std::cout << "Your account: " << account.name << ", " << account.accountNumber << ", " << account.balance;
}

