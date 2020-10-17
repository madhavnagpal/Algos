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
  int total_comp;
  dsu(int n)
  {
    total_comp = n;
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int get_superparent(int x)
  {
    if (x == parent[x])
      return x;
    return parent[x] = get_superparent(parent[x]);
  }

  void set_union(int x, int y)
  {
    int super_parent_x = get_superparent(x);
    int super_parent_y = get_superparent(y);
    if (super_parent_y != super_parent_x)
    {
      parent[super_parent_x] = super_parent_y;
      total_comp--;
    }
  }
};

void solve()
{

  dsu d(5);
  d.set_union(0, 1);
  d.set_union(2, 3);
  d.set_union(2, 1);

  cout << "super parents" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << i << " - " << d.parent[i] << endl;
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
  //cin>>test; for(int i=1;i<=test;i++)
  {
    solve();
  }
  return 0;
}
