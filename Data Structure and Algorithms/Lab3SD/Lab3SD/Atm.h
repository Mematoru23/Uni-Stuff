#pragma once
#include "Transaction.h"
#include "Collection.h"

class Atm
{
private:
	Transaction* transactions;
	Collection collection;
	int numberTransactions;

public:
	Atm();
	Atm(Transaction* transactions, Collection collection, int numberTransactions);
	~Atm() = default;

	int getNumberTransactions();
	Transaction* getAllTransactions();
	Collection getCollection();

	void setTransactions(Transaction* transactions);
	void setCollection(Collection collection);
	void setNumberTransactions(int numberTransactions);

	Atm operator=(Atm& a);
};