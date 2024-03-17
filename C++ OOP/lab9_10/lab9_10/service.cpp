#include "service.h"

void Service::addItem(int code, const std::string name, float price, int amount)
{
	Product p(code, name, price);
	this->repo.addItem(p, amount);
}

void Service::addBoughtItem(int code, const std::string name, float price, int amount)
{
	Product p(code, name, price);
	this->boughtProducts.push_back(std::make_pair(p, amount));
}

void Service::removeItem(int code)
{
	this->repo.removeItem(code);
}

std::vector<std::pair<Product, int>>& Service::getAll()
{
	return this->repo.getAll();
}

std::vector<std::pair<Product, int>>& Service::getAllBought()
{
	return this->boughtProducts;
}

void Service::buyProduct(int code, float money)
{
	if (!validCode(code))
		throw std::exception("no such code\n");
	for (int i = 0; i < getAll().size(); i++)
		if (getAll()[i].first.getCode() == code)
		{
			if (getAll()[i].first.getPrice() > money)
				throw std::exception("not enough money\n");
			int c = getAll()[i].first.getCode();
			std::string n = getAll()[i].first.getName();
			float p = getAll()[i].first.getPrice();
			if (getBoughtItemPos(c, n, p) == -1)
			{
				this->addBoughtItem(c, n, p, 1);
				this->setMoney(-getAll()[i].first.getPrice());
				this->removeItem(c);
				return;
			}
			this->getAllBought()[this->getBoughtItemPos(c, n, p)].second++;
			this->setMoney(-getAll()[i].first.getPrice());
			this->removeItem(c);
			return;
		}
}

int Service::getBoughtItemPos(int code, const std::string name, float price)
{
	for (int i = 0; i < getAllBought().size(); i++)
		if (getAllBought()[i].first.getCode() == code &&
			getAllBought()[i].first.getName() == name &&
			getAllBought()[i].first.getPrice() == price)
			return i;
	return -1;
}

bool Service::validCode(int code)
{
	for (int i = 0; i < getAll().size(); i++)
		if (getAll()[i].first.getCode() == code)
			return true;
	return false;
}

void Service::addMoney(float money)
{
	if (money <= 0)
		throw std::exception("invalid amount of money\n");
	this->money += money;
}

void Service::setMoney(float money)
{
	this->money += money;
}

float Service::getMoney()
{
	return this->money;
}
