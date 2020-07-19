// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// Lowest Common Ancestor
// Brute Force Approch
// worst case O(n) for each query hence needs to be optimised

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];
int depth[N], parent[N];

void dfs(int curr, int par)
{
  parent[curr] = par;
  for (auto child : graph[curr])
  {
    if (child != par)
    {
      depth[child] = depth[curr] + 1;
      dfs(child, curr);
    }
  }
}

int lca_brute(int u, int v)
{
  if (u == v)
    return u;
  if (depth[u] < depth[v])
    swap(u, v);

  while (depth[u] != depth[v])
    u = parent[u];

  while (u != v)
  {
    u = parent[u];
    v = parent[v];
  }
  return u;
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

  //Lca depends on what node you are using as Root node
  // here i am taking 1 as the root node

  dfs(1, 0);

  cout << lca_brute(11, 15) << endl;
  cout << lca_brute(10, 3) << endl;
  cout << lca_brute(7, 9) << endl;

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

// relationship
// 1 parent: 0 depth: 0
// 2 parent: 1 depth: 1
// 3 parent: 1 depth: 1
// 4 parent: 2 depth: 2
// 5 parent: 2 depth: 2
// 6 parent: 5 depth: 3
// 7 parent: 6 depth: 4
// 8 parent: 6 depth: 4
// 9 parent: 6 depth: 4
// 10 parent: 3 depth: 2
// 11 parent: 3 depth: 2
// 12 parent: 11 depth: 3
// 13 parent: 12 depth: 4
// 14 parent: 12 depth: 4
// 15 parent: 12 depth: 4
// 16 parent: 15 depth: 5
