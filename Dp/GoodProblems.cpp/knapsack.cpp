// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 5, M = 1e5 + 5;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, bag_capacity;
  cin >> n >> bag_capacity;

  vector<int> weights(n + 1), values(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> weights[i] >> values[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(bag_capacity + 1, 0));

  for (int w = weights[1]; w <= bag_capacity; w++)
  {
    dp[1][w] = values[1];
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j <= bag_capacity; j++)
    {
      int best = dp[i - 1][j];
      if (weights[i] <= j)
      {
        best = max(best, values[i] + dp[i - 1][j - weights[i]]);
      }
      dp[i][j] = best;
    }
  }
  cout << dp[n][bag_capacity] << endl;

  return 0;
}
