// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

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

  vector<pair<int, int>> graph[n + 1];
  for (int i = 0; i < m; i++)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].pb({weight, to});
    graph[to].pb({weight, from});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

  //src 1 so dist[src] = 0
  vector<bool> visited(n + 1, 0);
  q.push({0, 1});
  int mst = 0;

  while (!q.empty())
  {
    pair<int, int> curr = q.top();
    q.pop();

    if (visited[curr.second])
      continue;
    visited[curr.second] = 1;
    mst += curr.first;

    for (auto nbr : graph[curr.second])
    {
      if (!visited[nbr.second])
      {
        q.push(nbr);
      }
    }
  }
  cout << mst << endl;

  return 0;
}
