// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];

bool check(int src, vector<bool> &visited, vector<bool> &path) {
	visited[src] = 1;
	path[src] = 1;

	for (int child : graph[src]) {

		if (path[child]) {
			return true;
		} else if (!visited[child]) {
			bool next = check(child, visited, path);
			if (next)
				return true;
		}
	}

	path[src] = 0;
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
	}
	vector<bool> visited(n, 0), path(n, 0);

	bool hasCycle = check(0, visited, path);

	if (hasCycle)
		cout << "Cycle Found" << endl;
	else
		cout << "No cycle" << endl;
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
	//cin>>test; for(int i=1;i<=test;i++)
	{
		solve();
	}
	return 0;
}
