#include "inout.h"
#include "Atm.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateOption(int summ, Atm atm, Collection& collection)
{
	int i = 0;
	while (summ > 0)
	{
		if (atm.getCollection().getElements()[i] <= summ && atm.getCollection().getOccurences()[i] != 0)
		{
			collection.add(atm.getCollection().getElements()[i]);
			summ = summ - atm.getCollection().getElements()[i];
		}
		else
			i++;
	}
}

void saveTransactions(int& n, Atm& atm)
{
	int id, summ;
	Collection collection;
	Transaction* transactions;

	transactions = atm.getAllTransactions();
	cout << "Enter amount: ";
	cin >> summ;
	srand((unsigned int)time(0));
	id = rand() % 1000;
	generateOption(summ, atm, collection);

	for (int j = 0; j < collection.getDistinctElements() - 1; j++)
		cout << collection.getElements()[j] << " * " << collection.getOccurences()[j] << " + ";

	cout << collection.getElements()[collection.getDistinctElements() - 1] << " * " << collection.getOccurences()[collection.getDistinctElements() - 1];
	cout << "\nDo you agree to this method? \n";
	cout << "1. Yes\n" << "2. No\n";
	cout << "Answer: ";

	int command;
	cin >> command;

	switch (command)
	{
	case 1:
		transactions[n].setId(id);
		transactions[n].setSumm(summ);
		transactions[n].setCollection(collection);
		n++;
		break;
	case 2:
		cout << "Couldn't make the transaction!\n\n";
		break;
	}

	atm.setNumberTransactions(n);
	atm.setTransactions(transactions);
}

void printTransactions(Atm atm, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Transaction " << i + 1 << "\n";
		cout << "ID: " << atm.getAllTransactions()[i].getId() << " | ";
		cout << "Amount: " << atm.getAllTransactions()[i].getSumm() << " | ";
		cout << "Method of payment: ";
		Collection colectie = atm.getAllTransactions()[i].getCollection();

		for (int j = 0; j < colectie.getDistinctElements() - 1; j++)
			cout << colectie.getElements()[j] << " * " << colectie.getOccurences()[j] << " + ";

		cout << colectie.getElements()[colectie.getDistinctElements() - 1] << " * " << colectie.getOccurences()[colectie.getDistinctElements() - 1] << "\n\n";
	}
}

void options()
{
	cout << "Choose one of the options:\n";
	cout << "1. Make transactions\n";
	cout << "2. Show transactions\n";
	cout << "0. Exit.\n";
}

void runMenu(Collection collection)
{
	int n = 0;
	Transaction* transactions = new Transaction[20];
	bool value = true;
	Atm atm(transactions, collection, n);

	while (value)
	{
		options();
		int command;
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 1:
			saveTransactions(n, atm);
			break;
		case 2:
			printTransactions(atm, n);
			break;
		default:
		{
			cout << "Goodbye!\n";
			value = false;
		}
		}
	}
}