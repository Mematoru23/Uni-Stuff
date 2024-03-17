#include "square.h"
#include <iostream>

using namespace std;

Square::Square()
{
	this->name = "";
	this->A = make_pair(0, 0);
	this->B = make_pair(0, 0);
	this->C = make_pair(0, 0);
	this->D = make_pair(0, 0);
}

Square::Square(string name, pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D)
{
	this->name = name;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
}

Square::Square(const Square& sq)
{
	this->name = sq.name;
	this->A = sq.A;
	this->B = sq.B;
	this->C = sq.C;
	this->D = sq.D;
}

std::string Square::getName()
{
	return this->name;
}

vector<pair<int, int>> Square::getCoordonates()
{
	coords.push_back(A);
	coords.push_back(B);
	coords.push_back(C);
	coords.push_back(D);

	return coords;
}

void Square::setName(string name)
{
	this->name = name;
}

void Square::setCoordonates(pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
}

int Square::calculateDistance()
{
	int ab = sqrt((this->B.first - this->A.first) * (this->B.first - this->A.first) + (this->B.second - this->A.second) * (this->B.second - this->A.second));
	return ab;
}

bool Square::operator==(const Square& square)
{
	return (this->name == square.name) && (this->A == square.A) && (this->B == square.B) && (this->C == square.C) && (this->D == square.D);
}

bool Square::operator!=(const Square& square)
{
	return (this->name != square.name) || (this->A != square.A) || (this->B != square.B) || (this->C != square.C) || (this->D != square.D);
}

ostream& operator<<(ostream& os, const Square& sq)
{
	os << sq.name << ": (" << sq.A.first << ", " << sq.A.second << "), (" << sq.B.first << ", " << sq.B.second << "), (" 
		<< sq.C.first << ", " << sq.C.second << "), (" << sq.D.first << ", " << sq.D.second << ")\n";
	return os;
}

Square Square::operator=(const Square& square)
{
	this->name = square.name;
	this->A = square.A;
	this->B = square.B;
	this->C = square.C;
	this->D = square.D;

	return *this;
}

int Square::area()
{
	return this->calculateDistance() * this->calculateDistance();
}

int Square::perimeter()
{
	return 4 * this->calculateDistance();
}
