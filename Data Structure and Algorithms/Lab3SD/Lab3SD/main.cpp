#include "inout.h"

using namespace std;

void addMoney(Collection& collection) {
	collection.add(500);
	collection.add(200);
	collection.add(100);
	collection.add(50);
	collection.add(10);
	collection.add(5);
	collection.add(1);
}

int main()
{
	Collection collection;

	for (int i = 0; i < 50; i++)
		addMoney(collection);

	runMenu(collection);
}