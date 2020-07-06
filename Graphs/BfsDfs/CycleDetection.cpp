// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// Cycle Detection

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

  bool isCyclic(int node, map<int, bool> &visited, int parent)
  {
    visited[node] = true;
    for (auto nbr : h[node])
    {
      if (!visited[nbr])
      {
        bool next = isCyclic(nbr, visited, node);
        if (next)
          return next;
      }
      else if (nbr != parent)
      {
        return true;
      }
    } //child loop
    return false;
  } //is cylic

  bool checkCycle()
  {
    map<int, bool> visited;
    return isCyclic(0, visited, -1);
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

  // g.addEdge(0, 3);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  if (g.checkCycle())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
