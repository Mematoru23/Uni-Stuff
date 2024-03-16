#include "tests.h"
#include "transaction.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "assert.h"

void tests()
{
	testAdd();
	testElim();

	std::cout << "All tests passed\n";
}

void testAdd()
{
	Repo repo;
	Service service(repo);
	UI ui(service);

	// add transaction in list
	std::string s = "add 100 out pizza";
	std::vector<std::string> cmd;
	cmd = ui.cmds(s);
	Transaction t(repo.getToday(), stoi(cmd[1]), cmd[2], cmd[3]); // 2 / 100 / out / pizza
	repo.addInsert(t);
	assert(repo.getAll().size() == 1);
}

void testElim()
{
	Repo repo;
	Service service(repo);
	UI ui(service);

	std::string el = "add 100 out pizza";
	std::vector<std::string> cmd;
	cmd = ui.cmds(el);
	Transaction t(repo.getToday(), stoi(cmd[1]), cmd[2], cmd[3]); // 2 / 100 / out / pizza
	repo.addInsert(t);
	assert(repo.getAll().size() == 1);

	// elim day
	el = "elim 4";
	cmd.clear();
	cmd = ui.cmds(el);
	repo.elim(stoi(cmd[1]));
	assert(repo.getAll().size() == 1);

	// elim type
	repo.addInsert(t);
	assert(repo.getAll().size() == 2);
	el = "elim in";
	cmd.clear();
	cmd = ui.cmds(el);
	repo.elim(cmd[1]);
	assert(repo.getAll().size() == 2);

	el = "elim out";
	cmd.clear();
	cmd = ui.cmds(el);
	repo.elim(cmd[1]);
	assert(repo.getAll().size() == 0);
}

