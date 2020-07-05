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

  void bfs(int src)
  {
    map<int, bool> visited;
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      cout << curr << " ";

      for (int nbr : h[curr])
      {
        if (!visited[nbr])
        {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
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

  g.bfs(0);

  return 0;
}
