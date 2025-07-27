#include <iostream>
#include "Transaction.h"
#include <vector>
#include <array>
#include <windows.h>
double income = 10000;
void AssignCategory(Transaction& transaction) {

	switch (transaction.category)
	{
	case Food:
		transaction.categoryName = "Food";
		transaction.offset = -1;
		break;
	case Transportation:

		transaction.categoryName = "Transportation";
		transaction.offset = -1;
		break;
	case Entertainment:
		transaction.categoryName = "Entertainment";
		transaction.offset = -1;
		break;
	case Bills:
		transaction.categoryName = "Bills";
		transaction.offset = -1;
		break;
	case Income:
		transaction.categoryName = "Income";
		transaction.offset = 1;
		break;
	default:
		break;
	}

}
void addTransaction(std::vector<Transaction>* vec, Transaction newTransaction) {
	int choice = 0;
	if (newTransaction.amount != NULL)
	{
		AssignCategory(newTransaction);
		vec->push_back(newTransaction);
		return;
	}
	do
	{
		system("cls");
		std::cout << "Enter the Description of the transaction\n";
		std::getline(std::cin, newTransaction.description);
		system("cls");
		std::cout << "Enter the Amount of the transaction\n";
		std::cin >> newTransaction.amount;
		if (newTransaction.amount < 0 || newTransaction.amount>10000) {
			system("cls");
			std::cout << "Enter a Valid amount (0-10000)";
			Sleep(1500);
			continue;
		}

		system("cls");
		std::cout << "Select a Category for transaction\n1. Food\n2. Transportation\n3. Entertainment\n4. Bills\n5. Income\n";
		std::cin >> choice;
		if (choice < 1 || choice>6) {
			system("cls");
			std::cout << "Enter a Valid amount (1-5)";
			Sleep(1500);
			continue;
		}
	} while ((newTransaction.amount > 10000 || newTransaction.amount < 0) || (choice < 1 || choice>5));
	newTransaction.category = (TransactionCategory)(choice--);
	AssignCategory(newTransaction);
	vec->push_back(newTransaction);
}
void showAllTransactions(Transaction arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << "Description: " << arr[i].description << std::endl;
		std::cout << "Amount: " << arr[i].amount * arr[i].offset << "$" << std::endl;
		std::cout << "Category: " << arr[i].categoryName << std::endl;

	}
}
void GenerateTransactionData(std::vector<Transaction>* vec, int numberOfTransactions) {

	for (int i = 0; i < numberOfTransactions; i++)
	{
		Transaction test;

		test.description = "Test " + std::to_string(i + 1);
		test.amount = rand() % 10001;
		test.category = (TransactionCategory)(rand() % 5);
		addTransaction(vec, test);
	}

}
double addAllIncomes(std::vector<Transaction>* vec) {
	int totalIncome = 0;
	for (Transaction val : *vec)
	{
		if (val.category == Income)
			totalIncome += val.amount;
	}
	return totalIncome;
}
double addAllExpenses(std::vector<Transaction>* vec) {
	int totalExpense = 0;
	for (Transaction val : *vec)
	{
		if (val.category != Income)
			totalExpense += val.amount;
	}
	return totalExpense;
}
std::array<double,4> calculateCategory(std::vector<Transaction>* vec) {
	std::array<double, 4> categoryExpenses;
	for (Transaction val : *vec) {
		switch (val.category)
		{
		case Food:
			categoryExpenses[0] += val.amount;
			break;
		case Transportation:
			categoryExpenses[1] += val.amount;
			break;
		case Entertainment:
			categoryExpenses[2] += val.amount;
			break;
		case Bills:
			categoryExpenses[3] += val.amount;
			break;
		default:
			break;
		}
	}
	return categoryExpenses;
}
void calculatePercentages(std::vector<Transaction>* vec) {
	double allExpenses = addAllExpenses(vec);
	std::array<double, 4> categoryArray = calculateCategory(vec);
	system("cls");
	std::cout << "Percentages of Expense per Category\n";
	std::cout << "Food: " << (categoryArray[0] * 100) / allExpenses << "%\n";
	std::cout << "Transporatation: " << (categoryArray[1] * 100) / allExpenses << "%\n";
	std::cout << "Entertaiment: " << (categoryArray[2] * 100) / allExpenses << "%\n";
	std::cout << "Bills: " << (categoryArray[3] * 100) / allExpenses << "%\n";
}

void setBudgetLimits(double budgetLimit, double* budgetList[], TransactionCategory category) {
	switch (category)
	{
	case Food:
		*budgetList[0] = budgetLimit;
		break;
	case Transportation:
		*budgetList[1] = budgetLimit;
		break;
	case Entertainment:
		*budgetList[2] = budgetLimit;
		break;
	case Bills:
		*budgetList[3] = budgetLimit;
		break;
	default:
		std::cout << "Not a valid category to set a limit";
		break;
	}
}

void checkBudgetLimitsAlerts(Transaction transaction, double* budgetList[], std::vector<Transaction>* vec) {
	int choice;
	if (transaction.amount + calculateCategory(vec)[(int)transaction.category] > *budgetList[(int)transaction.category]) {
		std::cout << "This transaction is outside the budget.\n"; 
		std::cin >> choice;
	}
}



int main() {
	srand(time(0));
	std::array<double, 4> budgetsCategory = { 1000,1000,1000,1000 };
	std::vector<Transaction> transactions;
	Transaction transaction;
	int choice;

	std::cout << "####################\n########Menu########\n####################\n\n";
	std::cout << "1. Add Transaction\n2. All Transactions\n3. Category Summary\n4. Budget Status\n5. Financial Summary\n6. Exit";
	std::cin >> choice;

	MenuState state = (MenuState)choice;
	switch (state)
	{
	case AddTransaction:
		addTransaction(&transactions, transaction);
		break;
	case AllTransaction:
		showAllTransactions(transactions.data(), transactions.size());
		break;
	case CategoryAnalysis:
		calculatePercentages(&transactions);
		break;
	case BudgetStatus:
		std::cout << "Budget Status\n1. Set Budgets\n2. Check Budgets\n";
		std::cin >> choice;
		break;
	case FinancialSummary:
		break;
	case Exit:
		break;
	default:
		break;
	}
	return 0;
}