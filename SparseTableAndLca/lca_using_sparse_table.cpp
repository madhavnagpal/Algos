// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 25;

vector<int> graph[N];
int parent[N][M] = {0}, depth[N] = {0};

void dfs(int curr, int par)
{
	parent[curr][0] = par;
	for (int i = 1; i < M; i++)
	{
		parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
	}
	for (auto child : graph[curr])
	{
		if (child != par)
		{
			depth[child] = depth[curr] + 1;
			dfs(child, curr);
		}
	}
}

int lca_using_sparse_table(int u, int v)
{
	if (u == v)
		return u;
	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];

	for (int i = M - 1; i >= 0; i--)
	{
		if (diff & (1 << i))
		{
			u = parent[u][i];
		}
	}
	//u and v on same depth
	if (u == v)
		return u;

	for (int i = M - 1; i >= 0; i--)
	{
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);
	cout << lca_using_sparse_table(5, 10) << endl;
	cout << lca_using_sparse_table(15, 10) << endl;
	cout << lca_using_sparse_table(15, 3) << endl;

	return 0;
}

// 16
// 1 2
// 1 3
// 2 4
// 2 5
// 3 10
// 3 11
// 5 6
// 6 7
// 6 8
// 6 9
// 11 12
// 12 13
// 12 14
// 12 15
// 15 16