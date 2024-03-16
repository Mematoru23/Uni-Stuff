#pragma once
#include "transaction.h"
#include <vector>

class Repo
{
private:
	std::vector<Transaction> tranzactions;
	std::vector<std::vector<Transaction>> undoTransactions;

public:
	Repo();
	~Repo() = default;

	// commented in service
	void addInsert(Transaction& t);
	void elim(int day);
	void elim(const std::string type);
	void elim(int day, int x);
	void replace(Transaction& t, int cost);
	void listAll();
	void listAll(std::string type);
	void listAll(std::string sign, int cost);
	void listAll(int day);
	int sumMax(std::string type);
	int sumMax(std::string type, int day);
	void filter(std::string type);
	void filter(std::string type, int cost);
	void undo();

	int findTransaction(Transaction& t);
	int findTransaction(Transaction& t, int cost);
	std::vector<Transaction>& getAll();
	void validator(Transaction& t);
	int getToday();
};