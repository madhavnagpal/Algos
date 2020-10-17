// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int board[102] = {0};

class Graph {
	map<int, list<int>> h;
public:
	void addEdge(int u, int v) {
		h[u].push_back(v);
	}

	int sssp(int src, int dest)
	{
		map<int, int> dist;
		for (auto node_pair : h) {
			dist[node_pair.first] = INT_MAX;
		}
		dist[src] = 0;
		queue<int> q;
		q.push(src);

		while (!q.empty())
		{
			int curr = q.front();
			q.pop();

			for (auto node : h[curr]) {
				if (dist[node] == INT_MAX) {
					q.push(node);
					dist[node] = dist[curr] + 1;
				}
			}
		}//queue loop

		return dist[dest];
	}
};

void solve()
{
	memset(board, 0, sizeof(board));
	//taking ladders inp
	int n;
	cin >> n;

	while (n--) {
		int s, e;
		cin >> s >> e;
		board[s] = e - s;
	}

	// snakes
	cin >> n;

	while (n--) {
		int head, tail;
		cin >> head >> tail;
		board[head] = tail - head;
	}

	// build the graph
	Graph g;

	for (int i = 1; i < 101; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int j = i + dice;
			j += board[j];
			if (j <= 100) {
				g.addEdge(i, j);
			}
		}
	}
	g.addEdge(100, 100);

	cout << g.sssp(1, 100) << endl;

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int test;
	cin >> test;

	while (test--) {
		solve();
	}

	return 0;
}
