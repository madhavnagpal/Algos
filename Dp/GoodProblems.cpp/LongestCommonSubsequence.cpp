// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e3 + 5, mod = 1e9 + 7;

string str1, str2;
int dp[N][N];

int length_of_lcs(int i, int j)
{
  if (i == str1.size() or j == str2.size())
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int ans = INT_MIN;

  if (str1[i] == str2[j])
  {
    ans = 1 + length_of_lcs(i + 1, j + 1);
  }
  else
  {
    ans = max(length_of_lcs(i, j + 1), length_of_lcs(i + 1, j));
  }
  return dp[i][j] = ans;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> str1 >> str2;
  memset(dp, -1, sizeof dp);
  int len = length_of_lcs(0, 0);

  string ans = "";
  int i = 0, j = 0;

  while (len > 0)
  {
    if (str1[i] == str2[j])
    {
      ans += str1[i];
      len--, i++, j++;
    }
    else
    {
      if (dp[i][j + 1] > dp[i + 1][j])
      {
        j++;
      }
      else
      {
        i++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
