#pragma once
#include "repo.h"
#include <fstream>

class FileRepo : public Repo
{
private:
	std::string filename;
	void loadFromFile();
	void writeToFile();
	void addtoFile();

public:
	FileRepo(const std::string& filename) : Repo(), filename{ filename } { this->loadFromFile(); };
	~FileRepo() = default;

	void addItem(const Product& prod, int amount = 1) override;
	void removeItem(int code);
	
};