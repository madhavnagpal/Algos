// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> gr[N];
int vis[N] = {0};
bool odd_cycle = 0;

void dfs(int curr, int par, int color)
{
  vis[curr] = color;

  for (auto child : gr[curr])
  {
    if (vis[child] == 0)
    {
      dfs(child, curr, 3 - color);
    }
    else if (color == vis[child])
    {
      odd_cycle = 1;
    }
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

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    gr[u].pb(v);
    gr[v].pb(u);
  }

  dfs(1, 1, 1);

  if (odd_cycle)
  {
    cout << "Not Bipartate" << endl;
  }
  else
  {
    cout << "Bipartate" << endl;
  }
  return 0;
}
