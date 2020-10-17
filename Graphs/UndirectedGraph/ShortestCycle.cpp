// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];

void bfs(int src, int n, int &ans)
{

  vector<int> dist(n + 1, INT_MAX);

  queue<int> q;
  q.push(src);
  dist[src] = 0;

  while (!q.empty())
  {

    int curr = q.front();
    q.pop();

    for (auto nbr : graph[curr])
    {

      if (dist[nbr] == INT_MAX)
      {
        //nbr not visited
        dist[nbr] = dist[curr] + 1;
        q.push(nbr);
      }
      else if (dist[nbr] >= dist[curr])
      {
        int temp = dist[nbr] + dist[curr] + 1;
        ans = min(ans, temp);
      }
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  int ans = n + 1;

  for (int i = 1; i <= n; i++)
  {
    bfs(i, n, ans);
  }

  if (ans == n + 1)
  {
    cout << "No cycle" << endl;
  }
  else
  {
    cout << "shortest cycle of length:" << ans << endl;
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int test;
  // cin >> test; while (test--)
  {
    solve();
  }

  return 0;
}
