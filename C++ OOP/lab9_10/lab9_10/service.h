#pragma once
#include "repo.h"
#include "repoFile.h"

class Service
{
private:
	Repo repo;
	float money;
	std::vector<std::pair<Product, int>> boughtProducts;

public:
	Service(Repo& repo) : repo{ repo }, money(0) {};
	~Service() = default;

	void addItem(int code, const std::string name, float price, int amount);
	void addBoughtItem(int code, const std::string name, float price, int amount);
	void removeItem(int code);
	std::vector<std::pair<Product, int>>& getAll();
	std::vector<std::pair<Product, int>>& getAllBought();
	void buyProduct(int code, float money);
	int getBoughtItemPos(int code, const std::string name, float price);
	bool validCode(int code);

	void addMoney(float money);
	void setMoney(float money);
	float getMoney();
};