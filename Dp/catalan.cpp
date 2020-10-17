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
  n = 10;
  vector<int> catalan(n + 1, -1);
  catalan[0] = 1;
  catalan[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    catalan[i] = 0;
    for (int j = 1; j <= i; j++)
    {
      catalan[i] += catalan[j - 1] * catalan[i - j];
    }
  }

  for (int i = 1; i < 10; i++)
  {
    cout << i << " " << catalan[i] << endl;
  }

  return 0;
}
