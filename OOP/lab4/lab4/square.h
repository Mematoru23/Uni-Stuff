#pragma once
#include <string>

using namespace std;

class Square
{
private:
	int length;
	string name;

public:
	Square(string name, int length);
	~Square();

	string getName();
	int getLength();
	void setName(string name);
	void setLength(int length);

	bool operator==(const Square& square);
	bool operator!=(const Square& square);

	int area();
	int perimeter();
};