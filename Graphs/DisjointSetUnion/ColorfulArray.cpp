// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 2e5 + 5, mod = 1e9 + 7;

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
    if (x == parent[x])
      return x;
    return parent[x] = get(parent[x]);
  }

  void unite(int x, int y)
  {
    x = get(x);
    y = get(y);
    if (x != y)
    {
      parent[x] = parent[y] = max(parent[x], parent[y]);
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
  int n, q;
  cin >> n >> q;

  vector<int> queries[q];

  for (int i = 0; i < q; i++)
  {
    int l, r, c;
    cin >> l >> r >> c;
    queries[i] = {l, r, c};
  }

  dsu d(n + 2);
  vector<int> ans(n + 2, 0);

  for (int i = q - 1; i >= 0; i--)
  {
    int l = queries[i][0], r = queries[i][1], color = queries[i][2];
    int j = d.get(l);

    while (j <= r)
    {
      ans[j] = color;
      d.unite(j, j + 1);
      j = d.get(j);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
