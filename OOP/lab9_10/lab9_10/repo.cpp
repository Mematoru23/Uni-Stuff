#include "repo.h"

void Repo::addItem(const Product& prod, int amount)
{
	this->products.push_back(std::make_pair(prod, amount));
}

void Repo::removeItem(int code)
{
	for (int i = 0; i < getAll().size(); i++)
		if (getAll()[i].first.getCode() == code)
		{
			this->products.erase(this->products.begin() + i);
			return;
		}
	throw std::exception("no such product\n");
}

int Repo::getItemPos(const Product& prod)
{
	for (int i = 0; i < getAll().size(); i++)
		if (getAll()[i].first == prod)
			return i;
	return -1;
}

int Repo::getItemAmount(const Product& prod)
{
	for (int i = 0; i < getAll().size(); i++)
		if (getAll()[i].first == prod)
			return getAll()[i].second;
	return -1;
}

std::vector<std::pair<Product, int>>& Repo::getAll()
{
	return this->products;
}
