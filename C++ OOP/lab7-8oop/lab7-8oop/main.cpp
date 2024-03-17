#include <iostream>
#include "tests.h"
#include "ui.h"
#include "repo.h"
#include "service.h"

using namespace std;

int main()
{
	tests();
	Repo repo;
	Service service(repo);
	UI ui(service);
	ui.run();
}