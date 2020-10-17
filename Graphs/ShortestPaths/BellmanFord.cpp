// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

bool bellman_ford(int n, vector<vector<int>> &edges, vector<int> &dist)
{

  //in worst case we would require to iterate n-1 times
  // 1 --> 2 --> 3 --> 4  ...     --> n
  //in worst case like in right to left order
  //at each iteration at distances would be updated atmost i edge away
  for (int i = 1; i < n; i++)
  {
    for (auto x : edges)
    {
      int u, v, wt;
      u = x[0], v = x[1], wt = x[2];
      if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
      {
        //relax the edge
        dist[v] = dist[u] + wt;
      }
    }
  }
  //if still we can relax any edge that means we have got negative weight cycle int our graph
  for (auto x : edges)
  {
    int u, v, wt;
    u = x[0], v = x[1], wt = x[2];
    if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
    {
      return false;
    }
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

  vector<vector<int>> edges(m);
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    edges[i] = {u, v, wt};
  }
  vector<int> dist(n + 1, INT_MAX);
  dist[1] = 0;
  bool solved = bellman_ford(n, edges, dist);

  if (solved)
  {
    for (int i = 1; i <= n; i++)
    {
      cout << "shortest dist form 1 to " << i << " is " << dist[i] << endl;
    }
  }
  else
  {
    cout << "negative cycle detected" << endl;
  }
  return 0;
}
