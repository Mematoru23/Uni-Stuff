#include "repo.h"

Repo::Repo()
{
	this->squares = vector<Square>();
}

vector<Square>& Repo::getAll()
{
	return this->squares;
}

void Repo::addSquare(Square& sq)
{
	this->squares.push_back(sq);
}

void Repo::showAll()
{
	for (int i = 0; i < this->squares.size(); i++)
		cout << this->squares[i];
	cout << "\n";
}

Square Repo::bigestSquare()
{
	string s = "ABCD";
	Square m(s, make_pair(0, 0), make_pair(0, 0), make_pair(0, 0), make_pair(0, 0));
	for (int i = 0; i < this->getAll().size(); i++)
	{
		pair<int, int> a = this->squares[i].getCoordonates()[0];
		pair<int, int> b = this->squares[i].getCoordonates()[1];
		if (m.area() < this->squares[i].area())
			m = this->squares[i];
	}
	return m;
}

vector<Square> Repo::squaresInQuadran1()
{
	vector<Square> ans;
	for (int i = 0; i < this->getAll().size(); i++)
	{
		pair<int, int> a = this->squares[i].getCoordonates()[0];
		pair<int, int> b = this->squares[i].getCoordonates()[1];
		pair<int, int> c = this->squares[i].getCoordonates()[2];
		pair<int, int> d = this->squares[i].getCoordonates()[3];
		if (a.first >= 0 && a.second >= 0 && b.first >= 0 && b.second >= 0 && c.first >= 0 && c.second >= 0 && d.first >= 0 && d.second >= 0)
			ans.push_back(this->squares[i]);
	}
	return ans;
}

pair<int, int> Repo::longestSeqOfEqSqares()
{
	int currLength = 1, currIndex = 0, maxLength = 0, maxIndex = 0;
	pair<int, int> ans = make_pair(maxIndex, maxLength);
	if (this->getAll().size() == 1)
		return make_pair(0, 1);
	for (int i = 1; i < this->getAll().size(); i++) {
		Square sq1(this->getAll()[i - 1]);
		Square sq2(this->getAll()[i]);
		if (sq1 == sq2) {
			currLength++;
			if (currLength > maxLength) {
				maxLength = currLength;
				maxIndex = currIndex;
				ans.first = currIndex;
				ans.second = currLength;
			}
		}
		else {
			currLength = 1;
			currIndex = i;
			ans.first = i;
			ans.second = 1;
		}
	}
	return ans;
}

