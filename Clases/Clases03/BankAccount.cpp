#include "BankAccount.h"
#include <iostream>
BankAccount::BankAccount(std::string& owner, double balance)
	:_owner(owner), _balance(balance)
{
}

void BankAccount::Deposit(double amount) {
	if (amount > 0) {
		_balance += amount;

		std::cout << "Deposited $" << amount << "\n";
	}
	else
	{
		std::cout <<"Invalid Deposit amount" << "\n";
	}
	DisplayBalance();
}
void BankAccount::Withdraw(double amount) {
	if (amount > 0 && amount <= _balance ) {
		
		_balance -= amount;
		std::cout << "Withdrawn: $" << amount << "\n";
	}
	else
	{

		std::cout << "Invalid Withdraw amount";
	}
	DisplayBalance();
}
void BankAccount::DisplayBalance() {
	std::cout << _owner << "'s Account\n" << "Balance: " << _balance << "\n";
}