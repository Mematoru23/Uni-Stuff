#pragma once
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Square
{
private:
	pair<int, int> A, B, C, D;
	string name;
	vector<pair<int, int>> coords;

public:
	Square();
	Square(string name, pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D);
	Square(const Square& sq);
	~Square() = default;

	string getName();
	vector<pair<int, int>> getCoordonates();
	void setName(string name);
	void setCoordonates(pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D);
	int calculateDistance();

	bool operator==(const Square& square);
	bool operator!=(const Square& square);
	Square operator=(const Square& square);
	friend ostream& operator<<(ostream& os, const Square& sq);

	int area();
	int perimeter();
};