#pragma once
#include "service.h"

class UI
{
private:
	Service service;

	void addProducts();
	void menu();

	void addMoney();
	void addProduct();
	void buyProducts();
	void showAll();
	void showBought();
	void updateMoney();
	void deleteProduct();

public:
	UI(Service& service) : service(service) {};
	~UI() = default;

	void run();
};