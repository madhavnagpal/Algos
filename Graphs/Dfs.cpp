// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// DFS

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class Graph {
	map<int, list<int>> h;
public:
	void addEdge(int u, int v) {
		h[u].push_back(v);
		h[v].push_back(u);
	}

	void dfs_helper(int src, map<int, bool> &visited) {
		visited[src] = true;
		cout << src << " ";

		for (auto nbr : h[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void dfs(int src) {
		map<int, bool> visited;
		dfs_helper(src, visited);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph g;

	g.addEdge(0, 3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.dfs(0);


	return 0;
}
