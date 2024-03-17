#include <iostream>
#include <assert.h>
#include "tests.h"
#include "properties.h"

void testPrimeSeq()
{
	int x[] = { 3, 1, 6, 5, 7, 11, 3, 2, 2, 4 };
	int n = 11;
	assert(maxPrimeSeq(x, n)[0] == 5);
	assert(maxPrimeSeq(x, n)[5] == 2);
}

void testContrarySingnsSeq()
{
	int x[] = { 3, -1, 6, 5, -7, 11, -3, 2, 2, 4 };
	int n = 11;
	assert(maxContrarySignsSeq(x, n)[0] == 5);
}

void tests()
{
	testPrimeSeq();
	testContrarySingnsSeq();
}