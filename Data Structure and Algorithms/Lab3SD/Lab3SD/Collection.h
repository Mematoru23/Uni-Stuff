#pragma once
#include "DynamicVector.h"

typedef int TElem;

class Collection
{
private:
	DynamicVector elements, occurences;
	int distinctElements, capacity;

public:
	Collection();
	~Collection() = default;

	void add(TElem elem);
	bool remove(TElem elem);
	bool search(TElem elem);

	int getDistinctElements();
	int noOccurences(TElem elem);
	int* getElements();
	int* getOccurences();
};