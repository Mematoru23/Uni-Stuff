#include "Collection.h"
#include "DynamicVector.h"
#include <iostream>

using namespace std;

Collection::Collection()
{
	this->distinctElements = 0;
	this->capacity = 500;
	this->elements = DynamicVector(capacity);
	this->occurences = DynamicVector(capacity);
}

void Collection::add(TElem elem)
{
	if (this->elements.search(elem))
	{
		int poz = -1, i = 0;
		while ((poz == -1) && (i < this->elements.getLength()))
			if (this->elements.getAt(i) == elem)
				poz = i;
			else
				i++;
		int occ = this->occurences.getAt(poz);
		this->occurences.setAt(poz, occ + 1);
	}
	else
	{
		this->elements.add(elem);
		this->occurences.add(1);
	}
}

bool Collection::remove(TElem elem)
{
	if (search(elem))
	{
		int i = this->elements.getPosition(elem);
		this->elements.remove(i);
		this->occurences.remove(i);
		return true;
	}
	return false;
}

bool Collection::search(TElem elem)
{
	return this->elements.search(elem);
}

int Collection::getDistinctElements()
{
	return this->elements.getLength();
}

int Collection::noOccurences(TElem elem)
{
	int i = this->elements.search(elem);
	return this->occurences.getAt(i);
}

int* Collection::getElements()
{
	return this->elements.getElements();
}

int* Collection::getOccurences()
{
	return this->occurences.getElements();
}
