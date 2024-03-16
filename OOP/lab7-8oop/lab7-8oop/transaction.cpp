#include "transaction.h"

Transaction::Transaction()
{
	this->day = 0;
	this->cost = 0;
	this->type = "";
	this->description = "";
}

Transaction::Transaction(const Transaction& t)
{
	this->day = t.day;
	this->cost = t.cost;
	this->type = t.type;
	this->description = t.description;
}

Transaction::Transaction(int day, int cost, const std::string type, const std::string description)
{
	this->day = day;
	this->cost = cost;
	this->type = type;
	this->description = description;
}

int Transaction::getToday()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int day = newtime.tm_mday;
	return day;
}

int Transaction::getDay()
{
	return this->day;
}

int Transaction::getCost()
{
	return this->cost;
}

const std::string Transaction::getType()
{
	return this->type;
}

const std::string Transaction::getDescription()
{
	return this->description;
}

void Transaction::setDay(int day)
{
	if (day <= 0 || day > 31)
		throw std::exception("Day must be > 0 and < 31");
	this->day = day;
}

void Transaction::setCost(int cost)
{
	if (cost < 0)
		throw std::exception("Cost must be >= 0");
	this->cost = cost;
}

void Transaction::setType(const std::string type)
{
	if (this->type == "in" || this->type == "out")
		throw std::exception("Type must be 'in' or 'out'");
	this->type = type;
}

void Transaction::setDescription(const std::string description)
{
	if (this->description == "")
		throw std::exception("Description must contain something");
	this->description = description;
}

Transaction& Transaction::operator=(const Transaction& t)
{
	this->day = t.day;
	this->cost = t.cost;
	this->type = t.type;
	this->description = t.description;
	return *this;
}

bool Transaction::operator==(const Transaction& t)
{
	return this->day == t.day && this->cost == t.cost && this->type == t.type && this->description == t.description;
}

std::ostream& operator<<(std::ostream& os, const Transaction& t)
{
	return os << "Day: " << t.day << " / Cost: " << t.cost << " / Type: " << t.type << " / Description: " << t.description << "\n";
}

