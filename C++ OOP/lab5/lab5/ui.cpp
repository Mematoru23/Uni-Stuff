#include "ui.h"
#include "repo.h"
#include <string>
#include <iostream>

using namespace std;

void menu()
{
	string s = "";
	s += "1. Add sqare\n";
	s += "2. Show all squares\n";
	s += "3. Biggest square\n";
	s += "4. Only squares in the first quadran\n";
	s += "5. Longest seq of equal squares\n";
	s += "0. Exit\n";
	cout << s;
}

void ui()
{
	int cmd;
	Repo repo;
	while (true)
	{
		menu();
		std::cout << ">> ";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			string s;
			std::cout << "name: ";
			cin >> s;
			std::cout << "coords of point A: ";
			int x1, y1;
			cin >> x1 >> y1;
			std::cout << "coords of point B: ";
			int x2, y2;
			cin >> x2 >> y2;
			std::cout << "coords of point C: ";
			int x3, y3;
			cin >> x3 >> y3;
			std::cout << "coords of point D: ";
			int x4, y4;
			cin >> x4 >> y4;
			Square sq(s, make_pair(x1, y1), make_pair(x2, y2), make_pair(x3, y3), make_pair(x4, y4));
			repo.addSquare(sq);
			break;
		}
		case 2:
		{
			repo.showAll();
			break;
		}
		case 3:
		{
			cout << repo.bigestSquare() << "\n";
			break;
		}
		case 4:
		{
			for (int i = 0; i < repo.squaresInQuadran1().size(); i++)
				cout << repo.squaresInQuadran1()[i];
			cout << "\n";
			break;
		}
		case 5:
		{
			for (int i = repo.longestSeqOfEqSqares().first - 1; i < repo.longestSeqOfEqSqares().first + repo.longestSeqOfEqSqares().second; i++)
				cout << repo.getAll()[i];
			cout << "\n";
			break;
		}
		case 0:
			exit(false);
		}
	}
}

