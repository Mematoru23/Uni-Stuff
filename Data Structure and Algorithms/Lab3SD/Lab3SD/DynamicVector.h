#pragma once

typedef int TElem;

class DynamicVector
{
private:
	TElem* elements;
	int capacity, length;
	void resize();

public:
	DynamicVector() = default;
	DynamicVector(int capacity);
	~DynamicVector() = default;

	void add(TElem elem);
	void remove(int i);
	bool search(TElem elem);

	int getAt(int i);
	int* getElements();
	void setAt(int i, TElem value);
	int getLength();
	int getPosition(TElem elem);
};