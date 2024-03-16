#include "ui.h"

void UI::addProducts()
{
	this->service.addItem(21, "croissant", 5, 12);
	this->service.addItem(11, "fanta", 7, 12);
	this->service.addItem(34, "ciocolata", 3, 12);
	this->service.addItem(52, "knoppers", 2.5, 12);
}

void UI::menu()
{
	// adding products beforehand
	std::string show = "";
	show += "1. Add product\n";
	show += "2. Add money\n";
	show += "3. Buy products\n";
	show += "4. Show all products\n";
	show += "5. Show bought products\n";
	show += "6. Delete product\n";
	show += "0. Exit\n";

	std::cout << show;
}

void UI::run()
{
	//addProducts();
	int cmd;
	while (true)
	{
		this->updateMoney();
		menu();
		std::cout << ">> ";
		try
		{
			std::cin >> cmd;
			if (!std::cin)
				throw std::exception("no such command\n");
			switch (cmd)
			{
			case 1:
				addProduct();
				break;
			case 2:
				addMoney();
				break;
			case 3:
				buyProducts();
				break;
			case 4:
				showAll();
				break;
			case 5:
				showBought();
				break;
			case 6:
				deleteProduct();
				break;
			case 0:
				exit(false);
			default:
				continue;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void UI::addMoney()
{
	std::cout << "Enter amount: ";
	float money;
	std::cin >> money;
	try 
	{
		if (!std::cin)
			throw std::exception("invalid data\n");
		this->service.addMoney(money);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
}

void UI::addProduct()
{
	int code;
	std::string name;
	float price;
	int amount;
	try
	{
		if (!std::cin)
			throw std::exception("invalid data\n");
		std::cout << "Code: ";
		std::cin >> code;
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << "Price: ";
		std::cin >> price;
		std::cout << "Amount: ";
		std::cin >> amount;
		this->service.addItem(code, name, price, amount);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
}

void UI::buyProducts()
{
	std::cout << "Enter product code: ";
	int code;
	std::cin >> code;
	try
	{
		if (!std::cin)
			throw std::exception("invalid data\n");
		this->service.buyProduct(code, this->service.getMoney());
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
}

void UI::showAll()
{
	if (!this->service.getAll().size())
		return;
	for (int i = 0; i < this->service.getAll().size(); i++)
		std::cout << this->service.getAll()[i].first << this->service.getAll()[i].second << "\n";
}

void UI::showBought()
{
	if (!this->service.getAllBought().size())
		return;
	for (int i = 0; i < this->service.getAllBought().size(); i++)
		std::cout << this->service.getAllBought()[i].first << " / Bought: " <<
		this->service.getAllBought()[i].second << "\n";
}

void UI::updateMoney()
{
	std::cout << "Money: " << this->service.getMoney() << "\n";
}

void UI::deleteProduct()
{
	std::cout << "Enter product code to delete: ";
	int code;
	std::cin >> code;
	try
	{
		if (!std::cin)
			throw std::exception("invalid data\n");
		this->service.removeItem(code);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
}
