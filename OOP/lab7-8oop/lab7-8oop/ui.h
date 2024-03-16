#pragma once
#include "service.h"
#include <sstream>

class UI
{
private:
	Service& service;
	std::vector<std::string> output;

public:
	UI() = default;
	UI(Service& service) : service(service) { };
	~UI() = default;

	std::string menu();
	std::vector<std::string>& cmds(std::string input);
	void addInsert(std::vector<std::string> cmd);
	void elim(std::vector<std::string> cmd);
	void list(std::vector<std::string> cmd);
	void characteristics(std::vector<std::string> cmd);
	void filter(std::vector<std::string> cmd);
	void undo(std::vector<std::string> cmd);
	void run();
};