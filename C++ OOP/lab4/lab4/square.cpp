#include "square.h"

Square::Square(string name, int length)
{
	this->name = name;
	this->length = length;
}

Square::~Square()
{
	if (this->name != "")
	{
		this->name = "";
		this->length = 0;
	}
}

std::string Square::getName()
{
	return this->name;
}

int Square::getLength()
{
	return this->length;
}

void Square::setName(string name)
{
	this->name = name;
}

void Square::setLength(int length)
{
	this->length = length;
}

bool Square::operator==(const Square& square)
{
	return (this->name == square.name) && (this->length == square.length);
}

bool Square::operator!=(const Square& square)
{
	return (this->name != square.name) || (this->length != square.length);
}

int Square::area()
{
	return this->length * this->length;
}

int Square::perimeter()
{
	return this->length * 4;
}
