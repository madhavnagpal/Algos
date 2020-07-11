// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];
int tin[N], tout[N], timer;

void euler_path_1(int curr, int par)
{
  cout << curr << " ";
  tin[curr] = ++timer;
  for (auto child : graph[curr])
  {
    if (child != par)
    {
      euler_path_1(child, curr);
      cout << curr << " ";
      tout[curr] = ++timer;
    }
  }
  return;
}

void euler_path_2(int curr, int par)
{
  cout << curr << " ";
  tin[curr] = ++timer;
  for (auto child : graph[curr])
  {
    if (child != par)
    {
      euler_path_2(child, curr);
    }
  }
  tout[curr] = ++timer;
  cout << curr << " ";
  return;
}

void euler_path_3(int curr, int par)
{
  cout << curr << " ";
  tin[curr] = ++timer;
  for (auto child : graph[curr])
  {
    if (child != par)
    {
      euler_path_3(child, curr);
    }
  }
  tout[curr] = timer;
  return;
}

bool is_ancestor(int x, int y)
{
  //if x is ancestor of y
  return tin[x] <= tin[y] and tout[x] >= tout[y];
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
    graph[u].pb(v);
    graph[v].pb(u);
  }
  timer = 0;
  // euler_path_1(1, 0);
  // euler_path_2(1, 0);
  euler_path_3(1, 0);
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    cout << i << " tin " << tin[i] << " tout " << tout[i] << endl;
  }

  if (is_ancestor(5, 4))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
