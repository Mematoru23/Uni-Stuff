#include "Atm.h"

Atm::Atm()
{
	this->transactions = new Transaction[50];
	this->collection = Collection();
	this->numberTransactions = 0;
}

Atm::Atm(Transaction* transactions, Collection collection, int numberTransactions)
{
	this->transactions = transactions;
	this->collection = collection;
	this->numberTransactions = numberTransactions;
}

Atm Atm::operator=(Atm& a)
{
	this->transactions = a.transactions;
	this->collection = a.collection;
	this->numberTransactions = a.numberTransactions;
	return *this;
}

int Atm::getNumberTransactions()
{
	return this->numberTransactions;
}

Transaction* Atm::getAllTransactions()
{
	return this->transactions;
}

Collection Atm::getCollection()
{
	return this->collection;
}

void Atm::setTransactions(Transaction* transactions)
{
	this->transactions = transactions;
}

void Atm::setCollection(Collection collection)
{
	this->collection = collection;
}

void Atm::setNumberTransactions(int numberTransactions)
{
	this->numberTransactions = numberTransactions;
}

