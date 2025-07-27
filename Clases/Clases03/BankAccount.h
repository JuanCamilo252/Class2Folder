#pragma once
#include <string>

class BankAccount
{
public:
	BankAccount(std::string& owner, double balance = 0);
	void Deposit(double amount);
	void Withdraw(double amount);
	void DisplayBalance();

private:
	std::string _owner;
	double _balance;
};

