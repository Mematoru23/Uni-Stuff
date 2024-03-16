#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin("in.txt");

const int sz = 50;

int matAd[sz][sz];
int matIn[sz][sz];
vector<int> adiac[sz];
vector<pair<int, int>> sir;

void convertire(int n, int m)
{
	int x, y;
	for (int k = 0; k < m; k++)
	{
		fin >> x >> y;
		for (int i = 1; i <= n; i++)
		{
			matAd[x][y] = 1;
			matAd[y][x] = 1;
		}
	}

	cout << "Matrice de adiacenta\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << matAd[i][j] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (matAd[i][j] == 1 && matAd[j][i] == 1)
				adiac[i].push_back(j);
	}

	cout << "\nLista de adiacenta\n";
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < adiac[i].size(); j++)
			cout << adiac[i][j] << " ";
		cout << "\n";
	}

	cout << "\nMatrice de incidenta\n";
	int ok = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < adiac[i].size(); j++)
		{
			if (adiac[i][j] > i)
			{
				ok++;
				sir.push_back(make_pair(i, adiac[i][j]));
			}
		}

	}
	
	for (int i = 1; i <= ok; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (sir[i - 1].first == j)
				matIn[j][i] = 1;
			if (sir[i - 1].second == j)
				matIn[j][i] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= ok; j++)
			cout << matIn[i][j] << " ";
		cout << "\n";
	}

}

int main()
{
	int n, m;
	fin >> n >> m;
	convertire(n, m);

}