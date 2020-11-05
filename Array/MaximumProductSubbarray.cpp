#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n)
{
  long long ans, maxEndingHere, minEndingHere;
  ans = maxEndingHere = minEndingHere = arr[0];

  for (int i = 1; i < n; i++)
  {
    long long curr = arr[i];
    if (curr < 0)
      swap(maxEndingHere, minEndingHere);
    maxEndingHere = max(maxEndingHere * curr, curr);
    minEndingHere = min(minEndingHere * curr, curr);
    ans = max(ans, maxEndingHere);
  }
  return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << maxProduct(arr, n);
  return 0;
}