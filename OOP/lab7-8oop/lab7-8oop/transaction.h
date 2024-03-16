#pragma once
#include <string>
#include <exception>
#include <iostream>
#include <time.h>

class Transaction
{
private:
	int day;
	int cost;
	std::string type;
	std::string description;

public:
	// constructors/ destructor
	Transaction();
	Transaction(const Transaction& t);
	Transaction(int day, int cost, const std::string type, const std::string description);
	~Transaction() = default;

	// getters
	int getToday();
	int getDay();
	int getCost();
	const std::string getType();
	const std::string getDescription();

	// setters
	void setDay(int day);
	void setCost(int cost);
	void setType(const std::string type);
	void setDescription(const std::string description);

	// override of some operators
	Transaction& operator=(const Transaction& t);
	bool operator==(const Transaction& t);
	friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
};