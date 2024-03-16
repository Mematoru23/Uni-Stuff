#include "Dictionar.h"
#include "IteratorDictionar.h"
#include <iostream>

Dictionar::Dictionar() {
	this->cap = 2;
	this->len = 0;
	this->elems = new TElem[this->cap];
}

Dictionar::~Dictionar() {
	delete[] elems;
}

void Dictionar::redim()
{
	TElem* newDict = new TElem[2 * cap];
	for (int i = 0; i < len; i++)
	{
		newDict[i].first = elems[i].first;
		newDict[i].second = elems[i].second;
	}
	cap *= 2;
	delete[] elems;
	this->elems = newDict;
}

TValoare Dictionar::adauga(TCheie c, TValoare v) {
	if (len == cap)
		redim();
	for (int i = 0; i < len; i++)
		if (elems[i].first == c)
		{
			TValoare old = elems[i].second;
			elems[i].second = v;
			return old;
		}
	this->elems[len].first = c;
	this->elems[len].second = v;
	len++;
	return NULL_TVALOARE;
}



//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const {
	for (int i = 0; i < len; i++)
		if (elems[i].first == c)
			return elems[i].second;
	return NULL_TVALOARE;
}


TValoare Dictionar::sterge(TCheie c) {
	for (int i = 0; i < len; i++)
		if (elems[i].first == c)
		{
			TValoare val = elems[i].second;
			for (int j = i + 1; j < len; j++)
			{
				elems[i].first = elems[j].first;
				elems[i].second = elems[j].second;
			}
			len--;
			return val;
		}
	return NULL_TVALOARE;
}


int Dictionar::dim() const {
	return len;
}

bool Dictionar::vid() const {
	return len ? false : true;
}


IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


