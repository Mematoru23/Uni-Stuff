#include "Transaction.h"

Transaction::Transaction()
{
	this->idTransaction = 0;
	this->summ = 0;
	this->collection = Collection();
}

Transaction::Transaction(int id, int summ, Collection collection)
{
	this->idTransaction = id;
	this->summ = summ;
	this->collection = collection;
}

Transaction Transaction::operator=(Transaction& t)
{
	this->summ = t.summ;
	this->idTransaction = t.idTransaction;
	this->collection = t.collection;
	return *this;
}

Collection Transaction::getCollection()
{
	return this->collection;
}

int Transaction::getId()
{
	return this->idTransaction;
}

int Transaction::getSumm()
{
	return this->summ;
}

void Transaction::setId(int id)
{
	this->idTransaction = id;
}

void Transaction::setSumm(int summ)
{
	this->summ = summ;
}

void Transaction::setCollection(Collection collection)
{
	this->collection = collection;
}
