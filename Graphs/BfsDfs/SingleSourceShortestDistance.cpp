// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class Graph
{
  map<int, list<int>> h;

public:
  void addEdge(int u, int v)
  {
    h[u].push_back(v);
    h[v].push_back(u);
  }

  void SSSD(int src)
  {
    map<int, int> dist;

    for (auto node_pair : h)
    {
      int node = node_pair.first;
      dist[node] = INT_MAX;
    }

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
      int curr = q.front();
      q.pop();

      for (int nbr : h[curr])
      {
        if (dist[nbr] == INT_MAX)
        {
          q.push(nbr);
          dist[nbr] = dist[curr] + 1;
        }
      }
    }

    // print single source shortest distance

    for (auto node_pair : h)
    {
      int node = node_pair.first;
      int d = dist[node];
      cout << "Shortest dist of node:" << node << " from src is :" << d << endl;
    }
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

  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 2);
  g.addEdge(3, 4);
  g.addEdge(1, 2);
  g.addEdge(4, 5);

  g.SSSD(0);

  return 0;
}
