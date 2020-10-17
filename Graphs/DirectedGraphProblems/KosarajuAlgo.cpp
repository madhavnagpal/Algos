// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// finding all strongly connected components

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> gr[N], grr[N], components[N];
int visited[N] = {0};
vector<int> order;

void dfs(int cur)
{
  visited[cur] = 1;
  for (auto child : gr[cur])
  {
    if (!visited[child])
      dfs(child);
  }
  order.pb(cur);
}

void dfs_rev(int cur, int comp)
{
  visited[cur] = 1;
  components[comp].pb(cur);

  for (auto child : grr[cur])
  {
    if (!visited[child])
    {
      dfs_rev(child, comp);
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
    gr[u].pb(v);
    grr[v].pb(u);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
      dfs(i);
  }

  memset(visited, 0, sizeof(visited));
  int comp = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (!visited[order[i]])
    {
      dfs_rev(order[i], comp);
      comp++;
    }
  }

  cout << "printing components" << endl;

  for (int i = 0; i < comp; i++)
  {
    cout << i << " -->";
    for (auto el : components[i])
    {
      cout << el << " ";
    }
    cout << endl;
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
