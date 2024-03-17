#include "product.h"

Product::Product(int code, const std::string name, float price)
{
	this->code = code;
	this->name = name;
	this->price = price;
}

Product::Product(const Product& prod)
{
	this->code = prod.code;
	this->name = prod.name;
	this->price = prod.price;
}

Product::Product()
{
	this->code = 0;
	this->name = "";
	this->price = 0;
}

int Product::getCode()
{
	return this->code;
}

std::string Product::getName()
{
	return this->name;
}

float Product::getPrice()
{
	return this->price;
}

void Product::setCode(int c)
{
	this->code = c;
}

void Product::setName(const std::string n)
{
	this->name = n;
}

void Product::setPrice(float p)
{
	this->price = p;
}

std::istream& operator>>(std::istream& is, Product& prod)
{
	std::string line, now;
	getline(is, line);
	std::istringstream input(line);
	input >> prod.code; input >> now;
	input >> prod.name; input >> now;
	input >> prod.price; input >> now;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Product& prod)
{
	return os << prod.code << " | " << prod.name << " | " << prod.price << " | ";
}

bool Product::operator==(const Product& p)
{
	return this->code == p.code && this->name == p.name && this->price == p.price;
}

