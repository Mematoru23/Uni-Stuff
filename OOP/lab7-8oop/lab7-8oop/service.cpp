#include "service.h"

void Service::addInsert(int day, int cost, const std::string type, const std::string description)
{
	Transaction t(day, cost, type, description);
	this->repo.validator(t);
	this->repo.addInsert(t);
}

void Service::elim(int day)
{
	this->repo.elim(day);
}

void Service::elim(const std::string type)
{
	this->repo.elim(type);
}

void Service::elim(int day, int x)
{
	this->repo.elim(day, x);
}

void Service::replace(int day, const std::string type, const std::string description, int ncost)
{
	Transaction t(day, 0, type, description);
	this->repo.validator(t);
	this->repo.replace(t, ncost);
}

int Service::sumMax(std::string type)
{
	return this->repo.sumMax(type);
}

int Service::sumMax(std::string type, int day)
{
	return this->repo.sumMax(type, day);
}

void Service::filter(std::string type)
{
	this->repo.filter(type);
}

void Service::filter(std::string type, int cost)
{
	this->repo.filter(type, cost);
}

void Service::undo()
{
	this->repo.undo();
}

void Service::listAll()
{
	this->repo.listAll();
}

void Service::listAll(std::string type)
{
	this->repo.listAll(type);
}

void Service::listAll(std::string sign, int cost)
{
	this->repo.listAll(sign, cost);
}

void Service::listAll(int day)
{
	this->repo.listAll(day);
}

std::vector<Transaction>& Service::getAll()
{
	return this->repo.getAll();
}

int Service::getToday()
{
	return this->repo.getToday();
}

bool Service::isNumber(const std::string s)
{
	return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
