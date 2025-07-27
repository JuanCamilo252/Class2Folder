#pragma once

#include <string>

enum TransactionCategory
{
	Food,
	Transportation,
	Entertainment,
	Bills,
	Income
};
struct Transaction
{
	double amount = NULL;
	std::string description;
	TransactionCategory category;
	std::string categoryName;
	int offset;
};
enum MenuState
{
	AddTransaction = 1,
	AllTransaction,
	CategoryAnalysis,
	BudgetStatus,
	FinancialSummary,
	Exit
};


