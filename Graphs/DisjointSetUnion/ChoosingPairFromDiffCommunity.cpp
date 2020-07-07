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
  vector<int> parent, count_of_childs;

  dsu(int n)
  {
    parent.resize(n);
    count_of_childs.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      count_of_childs[i] = 1;
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
      count_of_childs[y] += count_of_childs[x];
      count_of_childs[x] = 0;
    }
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;

  dsu s(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    s.set_union(u, v);
  }
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int super_parent_i = s.get_super_parent(i);
    ans += n - s.count_of_childs[super_parent_i];
  }
  cout << ans / 2 << endl;
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
