// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// Sparse Table

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class sparse_table
{
public:
  vector<vector<int>> mat;
  int n, m;
  vector<int> power_of_2;

  sparse_table(int _n, int _m)
  {
    n = _n, m = _m;
    mat.resize(n);
    power_of_2.resize(n + 1);
    for (int i = 0; i < n; i++)
      mat[i].resize(m);
    for (int i = 2; i <= n; i++)
      power_of_2[i] = power_of_2[i / 2] + 1;
  }

  void build(vector<int> a)
  {
    for (int i = 0; i < n; i++)
      mat[i][0] = a[i];

    for (int j = 1; j < m; j++)
    {
      for (int i = 0; (i + (1 << j)) <= n; i++)
      {
        mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int query(int l, int r)
  {
    int pw = power_of_2[r - l];
    return min(mat[l][pw], mat[r - (1 << pw) + 1][pw]);
  }
};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int m = 0;
  int temp = n;
  while (temp)
  {
    m++;
    temp = temp >> 1;
  }
  sparse_table s(n, m + 1);
  s.build(a);

  cout << "query" << s.query(2, 9) << endl;
  return 0;
}
