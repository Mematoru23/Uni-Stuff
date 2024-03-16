#include "DynamicVector.h"

void DynamicVector::resize()
{
	this->capacity = this->capacity * 2;
	TElem* newArray = new TElem[this->capacity];
	for (int i = 0; i < this->length; i++)
		newArray[i] = this->elements[i];
	delete[] this->elements;
	this->elements = newArray;
}

DynamicVector::DynamicVector(int capacity)
{
	this->elements = new TElem[capacity]();
	this->length = 0;
	this->capacity = capacity;
}

void DynamicVector::add(TElem elem)
{
	if (this->length == capacity - 1)
		resize();
	elements[this->length++] = elem;
}

void DynamicVector::remove(int i)
{
	for (int j = 1; j < this->length - 1; j++)
		this->elements[j] = this->elements[j + 1];
	this->length--;
}

bool DynamicVector::search(TElem elem)
{
	int i = 0;
	while (i < this->length)
	{
		if (this->elements[i] == elem)
			return true;
		i++;
	}
	return false;
}

int DynamicVector::getAt(int i)
{
	return this->elements[i];
}

int* DynamicVector::getElements()
{
	return this->elements;
}

void DynamicVector::setAt(int i, TElem value)
{
	this->elements[i] = value;
}

int DynamicVector::getLength()
{
	return this->length;
}

int DynamicVector::getPosition(TElem elem)
{
	for (int i = 0; i < this->getLength(); i++)
		if (this->elements[i] == elem)
			return i;
	return -1;
}
