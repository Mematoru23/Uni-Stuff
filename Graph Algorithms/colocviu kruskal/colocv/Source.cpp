#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");

int n;
double sum;
bool vis[2000];
vector<double> adj[50000];
vector<pair<int, int>> points;
vector<tuple<int, int, double>> edges;

bool sorted(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
	return (get<2>(a) < get<2>(b));
}

void read()
{
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		fin >> x >> y;
		points.push_back({ x, y });
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int fst = points[i].first - points[j].first;
			int sec = points[i].second - points[j].second;
			double root = sqrt(fst * fst + sec * sec);
			edges.push_back({ i, j, root });
		}
	}
}

void dfs(int a, int b, bool& ok)
{
	if (a == b)
		ok = true;

	if (vis[a])
		return;
	
	vis[a] = true;
	for (int i = 0; i < adj[a].size(); i++)
		dfs(adj[a][i], b, ok);
}

void kruskal()
{
	read();
	sort(edges.begin(), edges.end(), sorted);

	for (auto e : edges)
	{
		bool ok = false;
		for (int i = 0; i <= 100; i++)
			vis[i] = false;

		dfs(get<0>(e), get<1>(e), ok);

		if (!ok)
		{
			adj[get<0>(e)].push_back(get<1>(e));
			adj[get<1>(e)].push_back(get<0>(e));
			sum = sum + get<2>(e);
		}
	}
	fout << sum;
}

int main() 
{
	kruskal();
}

