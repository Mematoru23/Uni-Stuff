#pragma once
#include "Collection.h"

class Transaction
{
private:
	int idTransaction, summ;
	Collection collection;

public:
	Transaction();
	Transaction(int id, int summ, Collection collection);
	~Transaction() = default;

	Collection getCollection();

	int getId();
	int getSumm();

	void setId(int id);
	void setSumm(int summ);
	void setCollection(Collection collection);

	Transaction operator=(Transaction& t);
};