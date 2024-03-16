#pragma once
#include "square.h"
#include <vector>
#include <iostream>

using namespace std;

class Repo 
{
private:
	vector<Square> squares;

public:
	Repo();
	~Repo() = default;

	vector<Square>& getAll();
	void addSquare(Square& sq);
	void showAll();
	Square bigestSquare();
	vector<Square> squaresInQuadran1();
	pair<int, int> longestSeqOfEqSqares();

};
