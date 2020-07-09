// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

//time complexity v^3

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
  vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    dist[u][v] = wt;
    dist[v][u] = wt;
  }

  for (int i = 1; i <= n; i++)
  {
    dist[i][i] = 0;
  }

  for (int phase = 1; phase <= n; phase++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][phase] + dist[phase][j]);
      }
    }
  }

  bool cycleDetected = 0;

  for (int i = 1; i <= n; i++)
  {
    if (dist[i][i] < 0)
      cycleDetected = 1;
  }
  if (cycleDetected)
  {
    cout << "negative cycle detected" << endl;
  }
  else
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
