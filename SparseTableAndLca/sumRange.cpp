// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// Range Sum Query using Sparse Table

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class sparse_table
{
public:
  vector<vector<int>> mat;
  int n, m;
  vector<int> p2;
  sparse_table(int _n, int _m)
  {
    n = _n, m = _m;

    mat.resize(n);
    p2.resize(n + 1);

    //2-d matrix resizing
    for (int i = 0; i < n; i++)
    {
      mat[i].resize(m);
    }
    // log array for fast processing of log2
    for (int i = 2; i <= n; i++)
    {
      p2[i] = p2[i / 2] + 1;
    }
  }

  void build(vector<int> a)
  {
    //0 th column
    for (int i = 0; i < n; i++)
    {
      mat[i][0] = a[i];
    }

    for (int col = 1; col < m; col++)
    {
      for (int row = 0; row + (1 << col) <= n; row++)
      {
        mat[row][col] = mat[row][col - 1] + mat[row + (1 << (col - 1))][col - 1];
      }
    }
  }

  int query(int l, int r)
  {
    int num = r - l + 1;
    int ans = 0;
    while (num and l <= r)
    {
      int pw = p2[num];
      ans += mat[l][pw];
      num -= (1 << pw);
      l += (1 << pw);
    }
    return ans;
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
  for (int i = n; i > 0; i = i >> 1)
  {
    m++;
  }

  sparse_table t(n, m + 1);
  t.build(a);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      cout << t.mat[i][j] << " ";
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << "l:" << l << " r:" << r << " sum:" << t.query(l, r) << endl;
  }
  return 0;
}
