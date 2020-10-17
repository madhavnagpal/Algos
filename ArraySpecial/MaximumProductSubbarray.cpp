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
  int a[] = {0, 0, -1, -2, -3};
  int n = sizeof(a) / sizeof(a[0]);

  int curr_max_product = a[0], curr_min_product = a[0],
      prev_max_product = a[0], prev_min_product = a[0];
  int ans = a[0];

  for (int i = 1; i < n; i++)
  {
    cout << "i:" << i << " curr_min_product" << curr_max_product << " curr_min_product:" << curr_min_product << endl;
    curr_max_product = max(prev_max_product * a[i], max(prev_min_product * a[i], a[i]));
    curr_min_product = min(prev_min_product * a[i], min(prev_max_product * a[i], a[i]));
    prev_min_product = curr_min_product;
    prev_max_product = curr_max_product;
    ans = max(ans, curr_max_product);
    cout << "i:" << i << " curr_max_product" << curr_max_product << " curr_min_product:" << curr_min_product << endl;
  }

  cout << ans << endl;

  return 0;
}