// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 25;

vector<int> graph[N];
int parent[N][M] = {0}, tin[N], tout[N], timer;

void dfs(int curr, int par)
{
  tin[curr] = ++timer;
  parent[curr][0] = par;
  for (int i = 1; i < M; i++)
  {
    parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
  }
  for (auto child : graph[curr])
  {
    if (child != par)
    {
      dfs(child, curr);
    }
  }
  tout[curr] = timer;
}

bool is_ancestor(int u, int v)
{
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}
int lca_using_time(int u, int v)
{
  if (is_ancestor(u, v) or u == v)
    return u;
  if (is_ancestor(v, u))
    return v;

  for (int i = M - 1; i >= 0; i--)
  {
    if (!is_ancestor(parent[u][i], v))
      u = parent[u][i];
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
  timer = 0;
  tin[0] = 0;
  tout[0] = n + 1; // 0 is universal parent
  dfs(1, 0);

  cout << lca_using_time(10, 3) << endl;
  cout << lca_using_time(10, 15) << endl;
  cout << lca_using_time(9, 10) << endl;

  return 0;
}
