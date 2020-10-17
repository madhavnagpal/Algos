// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

class dsu
{
public:
  vector<int> parent;

  dsu(int n)
  {
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int get(int x)
  {
    return (x == parent[x] ? x : parent[x] = get(parent[x]));
  }

  void unite(int x, int y)
  {
    x = get(x);
    y = get(y);
    if (x != y)
    {
      parent[x] = y;
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
  int n, e;
  cin >> n >> e;

  vector<vector<int>> edges(e);

  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {w, u, v};
  }

  sort(edges.begin(), edges.end());

  dsu d(n + 1);
  int ans = 0;

  for (int i = 0; i < e; i++)
  {
    int u = edges[i][1];
    int v = edges[i][2];
    int w = edges[i][0];

    if (d.get(u) != d.get(v))
    {
      cout << u << " " << v << " " << w << endl;
      d.unite(u, v);
      ans += w;
    }
  }
  cout << ans << endl;

  return 0;
}
