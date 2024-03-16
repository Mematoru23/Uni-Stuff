#include <iostream>
#include "tests.h"
#include "ui.h"

using namespace std;

int main()
{
	testAll();
	Repo repo;
	FileRepo frepo{ "output.txt" };
	Service service{ frepo };
	UI ui(service);

	ui.run();
}