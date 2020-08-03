// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long

// knapsack when weights are upto 1e9 and values are upto 1e3

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, knapsack_capacity;
  cin >> n >> knapsack_capacity;

  vector<int> weight(n + 1), value(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> weight[i] >> value[i];
  }
  int N = n * 1000 + 1;
  vector<vector<int>> dp(n + 1, vector<int>(N + 1, INT_MAX));

  dp[1][value[1]] = weight[1];
  dp[1][0] = 0;

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j < N; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= value[i])
      {
        dp[i][j] = min(dp[i][j], weight[i] + dp[i - 1][j - value[i]]);
      }
    }
  }

  int ans;
  for (int i = 0; i < N; i++)
  {
    if (dp[n][i] <= knapsack_capacity)
      ans = i;
  }

  cout << ans << endl;
  return 0;
}
