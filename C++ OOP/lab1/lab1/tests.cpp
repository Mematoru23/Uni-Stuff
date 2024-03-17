#include "program.h"
#include <assert.h>
#include <iostream>

void tests()
{
	int p1 = 5, p2 = 7;
	assert(isPrime(5) == true);
	assert(isPrime(10) == false);
	assert(answer(12, p1, p2) == true);
	int p11 = 5, p22 = 61;
	assert(answer(66, p11, p22) == true);
	int p = 0, pp = 0;
	assert(answer(123, p, pp) == false);
	std::cout << "tests passed\n";
}
