// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];
int n, m;

void solve()
{
  cin >> n >> m;
  vector<int> indegree(n, 0);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    indegree[v]++;
  }

  queue<int> q;

  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  while (!q.empty())
  {
    int curr = q.front();
    cout << curr << " ";
    q.pop();

    for (auto child : graph[curr])
    {
      indegree[child]--;
      if (indegree[child] == 0)
      {
        q.push(child);
      }
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
  int test;
  //cin>>test; for(int i=1;i<=test;i++)
  {
    solve();
  }
  return 0;
}
