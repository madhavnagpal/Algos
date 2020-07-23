// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];
int parent[N], depth[N], visited[N], tin[N], tout[N], timer = 0;

void dfs(int curr, int par)
{
  tin[curr] = ++timer;
  parent[curr] = par;
  visited[curr] = 1;
  for (auto child : graph[curr])
  {
    if (!visited[child])
    {
      depth[child] = depth[curr] + 1;
      dfs(child, curr);
    }
  }
  tout[curr] = timer;
}

bool solve()
{
  int farthest = 1, max_depth = 0;
  int k;
  cin >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
    if (depth[a[i]] > max_depth)
    {
      max_depth = depth[a[i]];
      farthest = a[i];
    }
    a[i] = parent[a[i]];
  }

  for (int i = 0; i < k; i++)
  {
    if (tin[farthest] >= tin[a[i]] and tout[farthest] <= tout[a[i]])
      continue;
    else
      return false;
  }
  return true;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;

  int u, v;
  for (int i = 1; i < n; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  tin[0] = 0;
  tout[0] = n + 1;
  dfs(1, 0);

  for (int i = 0; i < m; i++)
  {
    if (solve())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
