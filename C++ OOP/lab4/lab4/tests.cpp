#include <string>
#include <assert.h>
#include <iostream>

#include "tests.h"
#include "square.h"

void tests()
{
	std::string a = "ABCD";
	Square s1(a, 2);
	Square s3(a, 2);
	assert(s1.getLength() == 2);
	assert(s1.getName() == "ABCD");
	assert(s1.perimeter() == 8);
	assert(s1.area() == 4);
	assert(s1 == s3);
	s1.setLength(5);

	std::string b = "MNPQ";
	Square s2(b, 4);
	assert(s2.getLength() == 4);
	assert(s2.getName() == "MNPQ");
	assert(s2.perimeter() == 16);
	assert(s2.area() == 16);
	assert(s1 != s2);
	assert(s3 != s2);
	s2.setLength(10);
	assert(s2.getLength() == 10);

	std::cout << "All tests passed!";
}