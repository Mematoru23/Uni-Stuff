#pragma once
#include "repo.h"

class Service : public Repo
{
private:
	Repo& repo;

public:
	Service() = default;
	Service(Repo& repo) : repo(repo) { };
	~Service() = default;

	// add/ insert transaction in list
	void addInsert(int day, int cost, const std::string type, const std::string description);

	// eliminate/replace by different parameters specific transactions
	void elim(int day);
	void elim(const std::string type);
	void elim(int day, int x);
	void replace(int day, const std::string type, const std::string description, int ncost);

	// list specific transactions
	void listAll();
	void listAll(std::string type);
	void listAll(std::string sign, int cost);
	void listAll(int day);
	
	// print sum of costs of specific type/ max cost transaction
	int sumMax(std::string type);
	int sumMax(std::string type, int day);

	// save specific transaction by type and cost
	void filter(std::string type);
	void filter(std::string type, int cost);
	void undo();

	// getter for all transactions
	std::vector<Transaction>& getAll();

	// getter for today
	int getToday();
	// checker if a string is a number
	bool isNumber(const std::string s);
};