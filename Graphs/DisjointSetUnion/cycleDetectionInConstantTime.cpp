// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

//cycle detection

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

  int get_super_parent(int x)
  {
    if (x == parent[x])
      return x;
    return parent[x] = get_super_parent(parent[x]);
  }

  void set_union(int x, int y)
  {
    int super_parent_x = get_super_parent(x);
    int super_parent_y = get_super_parent(y);
    if (super_parent_x != super_parent_y)
    {
      parent[super_parent_x] = super_parent_y;
    }
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;

  dsu d(n);
  bool cycle = 0;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (d.get_super_parent(u) != d.get_super_parent(v))
    {
      d.set_union(u, v);
    }
    else
    {
      cycle = 1;
    }
  }
  if (cycle)
    cout << "cycle detected" << endl;
  else
    cout << "no cycle" << endl;
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
  //cin>>test; for(int i=1;i<=test;i++)
  {
    solve();
  }
  return 0;
}
