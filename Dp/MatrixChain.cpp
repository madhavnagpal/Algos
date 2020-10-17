// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

//Matrix chain multiplication for matrices
//lets do it for 4 matrices of (4x2),(2x3),(3x1),(1x3)
//in input it is given as 4 2 3 1 3
//ans min cost will be 26

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> a({4, 2, 3, 1, 3});

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int dp[100][100] = {0};
  int n = a.size() - 1;

  for (int i = 1; i < n; i++)
  {
    int row = 0, col = i;
    while (col < n)
    {
      int ans = INT_MAX;
      for (int pivot = row; pivot < col; pivot++)
      {
        ans = min(ans, dp[row][pivot] + dp[pivot + 1][col] + a[row] * a[pivot + 1] * a[col + 1]);
      }
      dp[row][col] = ans;
      row++, col++;
    }
  }

  cout << dp[0][n - 1] << endl;

  return 0;
}
