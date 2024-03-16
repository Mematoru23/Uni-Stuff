#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Product
{
private:
	int code;
	std::string name;
	float price;

public:
	Product();
	Product(int code, const std::string name, float price);
	Product(const Product& prod);
	~Product() = default;

	int getCode();
	std::string getName();
	float getPrice();
	void setCode(int c);
	void setName(const std::string n);
	void setPrice(float p);

	bool operator==(const Product& p);
	friend std::ostream& operator<<(std::ostream& os, const Product& prod);
	friend std::istream& operator>>(std::istream& is, Product& prod);
};