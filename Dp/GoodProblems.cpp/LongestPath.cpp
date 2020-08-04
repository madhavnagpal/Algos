// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// Longest path possible in directed acyclic graph

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];
int dp[N];

int solve(int curr)
{
  if (dp[curr] != -1)
    return dp[curr];
  int ans = -1;
  for (auto child : graph[curr])
  {
    ans = max(ans, solve(child));
  }
  return dp[curr] = 1 + ans;
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

  int u, v;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  memset(dp, -1, sizeof dp);
  int ans = INT_MIN;

  for (int i = 1; i <= n; i++)
  {
    if (dp[i] == -1)
    {
      ans = max(ans, solve(i));
    }
  }
  cout << ans << endl;

  return 0;
}
