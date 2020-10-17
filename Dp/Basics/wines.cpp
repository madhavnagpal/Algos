// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N], n;
int dp[100][100];

int solve(int i, int j, int year)
{
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int op1 = a[i] * year + solve(i + 1, j, year + 1);
  int op2 = a[j] * year + solve(i, j - 1, year + 1);
  return dp[i][j] = max(op1, op2);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, n - 1, 1);

  return 0;
}
