#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int oo = (1 << 30);
const int SZ = 11000;

int nodes, edges, startNode, k, d[SZ];
bool in_q[SZ];
vector<pair<int, int>> gr[SZ];

struct compare
{
	bool operator () (int x, int y) { return d[x] > d[y]; }
};

priority_queue< int, vector<int>, compare > q;

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	fin >> nodes >> edges >> startNode;
	for (int i = 0; i < edges; i++)
	{
		int x, y, v;
		fin >> x >> y >> v;
		gr[x].push_back(make_pair(y, v));
	}

	for (int i = 0; i < nodes; i++)
		d[i] = oo;

	d[startNode] = 0;
	q.push(startNode);
	in_q[startNode] = true;

	while (!q.empty())
	{
		int currNode = q.top();
		q.pop();
		in_q[currNode] = false;
		for (int i = 0; i < gr[currNode].size(); i++)
		{
			int vecin = gr[currNode][i].first;
			int cost = gr[currNode][i].second;

			if (d[currNode] + cost < d[vecin])
			{
				d[vecin] = cost + d[currNode];
				if (in_q[vecin] == false)
				{
					q.push(vecin);
					in_q[vecin] = true; 
				}
			}
		}
	}

	for (int i = 0; i < nodes; i++)
		d[i] != oo ? fout << d[i] << " " : fout << "INF ";


	fin.close();
	fout.close();
}