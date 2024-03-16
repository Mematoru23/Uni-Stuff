#include "repo.h"
#include <string>

Repo::Repo()
{
	this->tranzactions = std::vector<Transaction>();
}

void Repo::addInsert(Transaction& t)
{
	this->undoTransactions.push_back(this->tranzactions);
	this->tranzactions.push_back(t);
}

void Repo::elim(int day)
{
	this->undoTransactions.push_back(this->tranzactions);
	std::vector<Transaction> output;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getDay() != day)
			output.push_back(this->getAll()[i]);
	this->tranzactions.resize(output.size());
	this->tranzactions = output;
}

void Repo::elim(const std::string type)
{
	this->undoTransactions.push_back(this->tranzactions);
	std::vector<Transaction> output;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getType() != type)
			output.push_back(this->getAll()[i]);
	this->tranzactions.resize(output.size());
	this->tranzactions = output;
}

void Repo::elim(int day, int x)
{
	this->undoTransactions.push_back(this->tranzactions);
	std::vector<Transaction> output;
	for (int i = 0; i < this->tranzactions.size(); i++)
		if (this->tranzactions[i].getDay() < day || this->tranzactions[i].getDay() > day + x)
			output.push_back(this->tranzactions[i]);
	this->tranzactions.resize(output.size());
	this->tranzactions = output;
}

void Repo::replace(Transaction& t, int cost)
{
	this->undoTransactions.push_back(this->tranzactions);
	this->tranzactions[this->findTransaction(t, 0)].setCost(cost);
}

void Repo::listAll()
{
	for (int i = 0; i < this->getAll().size(); i++)
		std::cout << this->getAll()[i];
}

void Repo::listAll(std::string type)
{
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getType() == type)
			std::cout << this->getAll()[i];
}

void Repo::listAll(std::string sign, int cost)
{
	if (sign == ">")
	{
		for (int i = 0; i < this->getAll().size(); i++)
			if (this->getAll()[i].getCost() > cost)
				std::cout << this->getAll()[i];
		return;
	}
	if (sign == "=")
	{
		for (int i = 0; i < this->getAll().size(); i++)
			if (this->getAll()[i].getCost() == cost)
				std::cout << this->getAll()[i];
		return;
	}
	return;
}

void Repo::listAll(int day)
{
	int in = 0, out = 0;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getDay() == day && this->getAll()[i].getType() == "in")
			in += this->getAll()[i].getCost();

	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getDay() == day && this->getAll()[i].getType() == "out")
			out += this->getAll()[i].getCost();

	if (in == 0 && out == 0)
		throw std::exception("day not in list\n");
	std::cout << in - out << "\n";
}

int Repo::sumMax(std::string type)
{
	int output = 0;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getType() == type)
			output += this->getAll()[i].getCost();
	return output;
}

int Repo::sumMax(std::string type, int day)
{
	int maximum = -1;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getType() == type && this->getAll()[i].getDay() == day)
			if (this->getAll()[i].getCost() > maximum)
				maximum = this->getAll()[i].getCost();
	return maximum;
}

int Repo::findTransaction(Transaction& t)
{
	if (!this->tranzactions.size())
		throw std::exception("no elements in list");
	for (int i = 0; i < this->getAll().size(); i++)
		if (t == this->getAll()[i])
			return i;
	return -1;
}

int Repo::findTransaction(Transaction& t, int cost)
{
	if (!this->tranzactions.size())
		throw std::exception("no elements in list");
	for (int i = 0; i < this->getAll().size(); i++)
		if (t.getDay() == this->tranzactions[i].getDay() && t.getType() == this->tranzactions[i].getType() && t.getDescription() == this->tranzactions[i].getDescription())
			return i;
	return -1;
}

std::vector<Transaction>& Repo::getAll()
{
	return this->tranzactions;
}

void Repo::filter(std::string type)
{
	this->undoTransactions.push_back(this->tranzactions);
	std::vector<Transaction> output;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getType() == type)
			output.push_back(this->getAll()[i]);
	this->tranzactions.resize(output.size());
	this->tranzactions = output;
}

void Repo::filter(std::string type, int cost)
{
	this->undoTransactions.push_back(this->tranzactions);
	std::vector<Transaction> output;
	for (int i = 0; i < this->getAll().size(); i++)
		if (this->getAll()[i].getType() == type && this->getAll()[i].getCost() < cost)
			output.push_back(this->getAll()[i]);
	this->tranzactions.resize(output.size());
	this->tranzactions = output;
}

void Repo::undo()
{
	if (this->undoTransactions.size())
	{
		this->tranzactions = this->undoTransactions.back();
		this->undoTransactions.pop_back();
		return;
	}
	throw std::exception("can't do more undo\n");
}

void Repo::validator(Transaction& t)
{
	std::string s = "";
	if (t.getCost() < 0)
		s += "Cost cannot be negative!\n";
	if (s != "")
		throw std::exception(s.c_str());
}

int Repo::getToday()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int day = newtime.tm_mday;
	return day;
}
