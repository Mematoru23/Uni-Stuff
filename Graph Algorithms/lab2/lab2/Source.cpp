#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
ifstream fin("graf.txt");

vector<int> gr[100];
int main()
{
	int n, m;
	fin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		fin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	queue<int> q;
	int dist[100];
	for (int i = 0; i <= n; i++)
		dist[i] = -1;
	q.push(1);
	dist[1] = 0;

	while (!q.empty())
	{
		int nod = q.front();
		q.pop();
		cout << nod << "--";
		for (int i = 0; i < gr[nod].size(); i++)
		{
			if (dist[gr[nod][i]] == -1)
			{
				q.push(gr[nod][i]);
				dist[gr[nod][i]] = dist[nod] + 1;
			}
			cout << gr[nod][i] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";

}
//int nrcomp, frecv[250];
//int vertices, edges;
//vector<int> gr[250];
//
//void DFS(int nod) {
//	frecv[nod] = 1;
//	for (int i = 0; i < gr[nod].size(); i++)
//		if (!frecv[gr[nod].at(i)])
//		{
//			DFS(gr[nod].at(i));
//			cout << gr[nod][i];
//		}
//}
//
//void comp() {
//	for (int i = 1; i <= vertices; i++)
//		if (!frecv[i]) {
//			cout << i << " ";
//			DFS(i);
//		}
//}
//
//int main(int argc, const char* argv[]) {
//	fin >> vertices >> edges;
//	for (int i = 0; i < edges; i++) {
//		int x, y;
//		fin >> x >> y;
//		gr[x].push_back(y);
//		gr[y].push_back(x);
//	}
//	comp();
//}