#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("text.txt");
ofstream fout("text.out");

const int N = 100005, M = 500500;

int n, m;
int from[M], to[M];
bool visited[M];
vector <int> v[N];
vector <int> path;
stack <int> s;

void read()
{
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		fin >> x >> y;
		v[x].push_back(i);
		v[y].push_back(i);
		from[i] = x;
		to[i] = y;
	}
}

void print()
{
	for (int i = 0; i < path.size(); i++)
		fout << path[i] << " ";
}

bool isCicle()
{
	for (int i = 0; i < n; i++)
		if (v[i].size() % 2 == 1)
			return false;

	return true;
}

void euler(int startNode)
{
	s.push(startNode);
	while (!s.empty())
	{
		int node = s.top();
		if (!v[node].empty())
		{
			int edge = v[node].back();
			v[node].pop_back();
			if (!visited[edge])
			{
				visited[edge] = true;
				if (to[edge] != node)
					s.push(to[edge]);
				else
					s.push(from[edge]);
			}
		}
		else
		{
			path.push_back(node);
			s.pop();
		}
	}
}

int main()
{
	read();
	if (!isCicle())
		return 0;

	euler(0);
	print();
}