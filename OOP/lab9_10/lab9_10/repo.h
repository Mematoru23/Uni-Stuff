#pragma once
#include "product.h"
#include <vector>

class Repo
{
private:
	std::vector<std::pair<Product, int>> products;

public:
	Repo() = default;
	~Repo() = default;

	virtual void addItem(const Product& prod, int amount = 1);
	void removeItem(int code);
	int getItemPos(const Product& prod);
	int getItemAmount(const Product& prod);
	std::vector<std::pair<Product, int>>& getAll();
	int getAmount(const Product& prod);
};

class RepoException
{
	std::string msg;
public:
	RepoException(std::string m) : msg{ m } {}
	std::string getErrorMessage() { return this->msg; }
};