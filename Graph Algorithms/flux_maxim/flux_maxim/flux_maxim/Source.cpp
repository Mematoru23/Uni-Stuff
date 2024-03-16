#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 1e3;
const int INF = 1e9;

vector <int> edges[NMAX + 1];
int flow[NMAX + 1][NMAX + 1];
int dist[NMAX + 1];
int first_good[NMAX + 1];

int s, d;

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

void add_edge() {
    int a, b, c;
    fin >> a >> b >> c;
    if (flow[b][a] == 0) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    flow[a][b] = c;
}

bool bfs() {
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : edges[node]) {
            if (flow[node][it] > 0 && dist[it] == -1) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return (dist[d] != -1);
}

int dfs(int node, int pushed) {
    if (!pushed) return 0;
    if (node == d) return pushed;
    for (int& i = first_good[node]; i < edges[node].size(); i++) {
        int nxt = edges[node][i];
        if (!flow[node][nxt] || dist[nxt] != dist[node] + 1) continue;
        int aux = dfs(nxt, min(pushed, flow[node][nxt]));
        if (!aux) continue;
        flow[node][nxt] -= aux;
        flow[nxt][node] += aux;
        return aux;
    }
    return 0;
}

int n;

int flux() {
    int ans = 0, aux;
    while (1) {
        if (!bfs()) break;
        for (int i = 1; i <= n; i++) first_good[i] = 0;
        while ((aux = dfs(s, INF)) != 0)
            ans += aux;
    }
    return ans;
}

int main() {
    int m;
    fin >> n >> m;
    s = 1, d = n;
    for (int i = 0; i < m; i++) {
        add_edge();
    }
    cout << flux();
    return 0;
}