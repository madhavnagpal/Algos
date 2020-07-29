// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;

  while (cin >> n)
  {
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    int sum = 0;
    vector<int> csum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      sum = (sum + a[i]) % 100;
      csum[i] = sum;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
      int row = 1, col = i + 1;
      while (col <= n)
      {
        int val = INT_MAX;
        for (int pivot = row; pivot < col; pivot++)
        {
          int temp = dp[row][pivot] + dp[pivot + 1][col] + ((csum[pivot] - csum[row - 1] + 100) % 100) * ((100 + csum[col] - csum[pivot]) % 100);
          val = min(val, temp);
        }
        dp[row][col] = val;
        row++, col++;
      }
    }
    cout << dp[1][n] << endl;
  }

  return 0;
}
