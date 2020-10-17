// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<list<pair<int, int>>> graph;

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

  graph.resize(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    graph[u].pb({wt, v});
    graph[v].pb({wt, u});
  }
  vector<int> dist(n + 1, INT_MAX);
  vector<bool> visited(n + 1, 0);

  set<pair<int, int>> s;
  s.insert({0, 1});

  while (!s.empty())
  {
    auto it = s.begin();
    pair<int, int> p = {it->first, it->second};
    dist[p.second] = p.first;
    visited[p.second] = 1;
    s.erase(it);

    for (auto node : graph[p.second])
    {
      int nbr = node.second;

      if (!visited[nbr])
      {
        int temp = p.first + node.first;
        if (temp < dist[nbr])
        {
          s.erase({dist[nbr], nbr});
          dist[nbr] = temp;
          s.insert({dist[nbr], nbr});
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << "shortest distance from 1 to " << i << " is " << dist[i] << endl;
  }

  return 0;
}
