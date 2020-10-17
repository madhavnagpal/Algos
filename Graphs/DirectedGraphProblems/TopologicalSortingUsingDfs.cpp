// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

map<string, list<string>> h;
map<string, bool> visited;
list<string> ordering;

void dfs(string src)
{
  visited[src] = 1;

  for (auto child : h[src])
  {
    if (!visited[child])
    {
      dfs(child);
    }
  }
  ordering.push_front(src);
}

void solve()
{
  h["Python"].pb("Data Preprocessing");
  h["Python"].pb("PyTorch");
  h["Python"].pb("ML Basics");
  h["Data Preprocessing"].pb("ML Basics");
  h["PyTorch"].pb("Deep Learning");
  h["ML Basics"].pb("Deep Learning");

  for (auto node : h)
  {
    if (!visited[node.first])
    {
      dfs(node.first);
    }
  }
  for (auto str : ordering)
  {
    cout << str << endl;
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
