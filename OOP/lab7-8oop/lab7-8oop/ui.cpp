#include "ui.h"

std::string UI::menu()
{
	std::string show = "<----------MENU---------->\n";
	show += "|| add <Cost> <Type> <Desc> || :-> add transaction in list of transactions\n";
	show += "|| insert <Day> <Cost> <Type> <Desc> || :-> insert transaction in list for a specific day\n";
	show += "|| elim <day> || :-> eliminate transactions from a specific day\n";
	show += "|| elim <x> to <day> || :-> eliminate transactions from specific day until x days after\n";
	show += "|| elim <type> || :-> eliminate transactions with a specific type: 'in' or 'out'\n";
	show += "|| replace <day> <type> <desc> with <cost> || :-> replace cost in transaction from specific day & type & description\n";
	show += "|| list || :-> list all transactions\n";
	show += "|| list <type> || :-> list transactions by type\n";
	show += "|| list > <cost> || :-> list transactions higher than cost\n";
	show += "|| list = <cost> || :-> list transactions equal with cost\n";
	show += "|| list sol <day> || :-> list sold of transactions from day(diff of sum of <in> with sum of <out>)\n";
	show += "|| sum <type> || - print sum of transactions of type\n";
	show += "|| max <type> <day> || - print max transaction from a day of a certain type\n";
	show += "|| filter <type>|| - save only transactions with type\n";
	show += "|| filter <type> <cost>|| - save only transactions with type and lower cost\n";
	show += "|| undo || - return to last operation\n";
	show += "|| exit || :-> exit program\n";

	return show;
}

std::vector<std::string>& UI::cmds(std::string input)
{
	this->output = std::vector<std::string>();
	std::stringstream cmd(input);
	std::string word;
	while (cmd >> word)
		this->output.push_back(word);
	return this->output;
}

void UI::addInsert(std::vector<std::string> cmd)
{
	try {
		if (cmd.size() < 4 && cmd[0] == "add")
			throw std::exception("\nNot enough parameters. Need 4!\n");
		if (cmd.size() < 5 && cmd[0] == "insert")
			throw std::exception("\nNot enough parameters. Need 5!\n");
		if (cmd.size() == 4 && cmd[0] == "add")
		{
			int day = this->service.getToday();
			int cost = stoi(cmd[1]);
			std::string type = cmd[2];
			std::string desc = cmd[3];
			this->service.addInsert(day, cost, type, desc);
			this->service.listAll();
			return;
		}
		if (cmd.size() == 5 && cmd[0] == "insert")
		{
			int day = stoi(cmd[1]);
			int cost = stoi(cmd[2]);
			std::string type = cmd[3];
			std::string desc = cmd[4];
			this->service.addInsert(day, cost, type, desc);
			this->service.listAll();
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void UI::elim(std::vector<std::string> cmd)
{
	try {
		if (cmd.size() < 2 && cmd[0] == "elim")
			throw std::exception("\nNot enough parameters. Need 2 or 4!\n");
		if (cmd.size() < 6 && cmd[0] == "replace")
			throw std::exception("\nNot enough parameters. Need 6!\n");
		if (cmd.size() == 2 && cmd[0] == "elim")
		{
			if (this->service.isNumber(cmd[1]))
			{
				this->service.elim(stoi(cmd[1]));
				this->service.listAll();
				return;
			}
			this->service.elim(cmd[1]);
			return;
		}
		if (cmd.size() == 4 && cmd[0] == "elim")
		{
			this->service.elim(stoi(cmd[3]), stoi(cmd[1]));
			this->service.listAll();
			return;
		}
		if (cmd.size() == 6 && cmd[0] == "replace")
		{
			this->service.replace(stoi(cmd[1]), cmd[2], cmd[3], stoi(cmd[5]));
			this->service.listAll();
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void UI::list(std::vector<std::string> cmd)
{
	switch (cmd.size())
	{
	case 1:
		this->service.listAll();
		break;
	case 2:
		this->service.listAll(cmd[1]);
		break;
	case 3:
	{
		if (cmd[1] == ">" || cmd[1] == "=")
		{
			this->service.listAll(cmd[1], stoi(cmd[2]));
			break;
		}
		if (cmd[1] == "sol")
		{
			this->service.listAll(stoi(cmd[2]));
			break;
		}
		break;
	}
	}
}

void UI::characteristics(std::vector<std::string> cmd)
{
	switch (cmd.size())
	{
	case 2:
		if (cmd[0] == "sum")
			std::cout << this->service.sumMax(cmd[1]) << "\n";
		break;
	case 3:
		if (cmd[0] == "max")
			std::cout << this->service.sumMax(cmd[1], stoi(cmd[2])) << "\n";
		break;
	}
}

void UI::filter(std::vector<std::string> cmd)
{
	switch (cmd.size())
	{
	case 2:
		this->service.filter(cmd[1]);
		this->service.listAll();
		break;
	case 3:
		this->service.filter(cmd[1], stoi(cmd[2]));
		this->service.listAll();
		break;
	}
}

void UI::undo(std::vector<std::string> cmd)
{
	try {
		this->service.undo();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void UI::run()
{
	std::cout << this->menu();
	while (true)
	{
		std::cout << ">> ";
		try {
			std::string commands;
			std::getline(std::cin, commands);
			std::vector<std::string> cmd = this->cmds(commands);
			if (!cmd.size())
				continue;
			std::string funct = cmd[0];
			if (funct == "add" || funct == "insert")
				addInsert(cmd);
			else if (funct == "elim" || funct == "replace")
				elim(cmd);
			else if (funct == "list")
				list(cmd);
			else if (funct == "sum" || funct == "max")
				characteristics(cmd);
			else if (funct == "filter")
				filter(cmd);
			else if (funct == "undo")
				undo(cmd);
			else if (funct == "exit")
				exit(false);
			else
				throw std::exception("no such command\n");
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
		}
	}
}
