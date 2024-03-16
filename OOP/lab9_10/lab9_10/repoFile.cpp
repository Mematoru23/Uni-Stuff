#include "repoFile.h"

void FileRepo::loadFromFile()
{
	std::ifstream in(this->filename, std::ios::in);

	if (!in.is_open())
		throw RepoException("Open error: " + this->filename + "\n");

	if (in.peek() == std::ifstream::traits_type::eof())
		return;

	while (!in.eof()) {
		if (in.peek() == std::ifstream::traits_type::eof())
			return;

		Product prod;
		in >> prod;
		Repo::addItem(prod);
	}
}

void FileRepo::writeToFile()
{
	std::ofstream out(this->filename, std::ios::trunc);

	if (!out.is_open())
		throw RepoException("Open error: " + this->filename + "\n");

	for (const auto& prod : getAll())
		out << prod.first;
}

void FileRepo::addItem(const Product& prod, int amount)
{
	Repo::addItem(prod);
	this->writeToFile();
}

void FileRepo::removeItem(int code)
{
	Repo::removeItem(code);
	this->writeToFile();
}
