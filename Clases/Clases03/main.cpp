#include "BankAccount.h"

int main() {
	std::string owner = "Juan";
	BankAccount account(owner);
	account.Deposit(500);
	account.Withdraw(200);

	return 0;
}