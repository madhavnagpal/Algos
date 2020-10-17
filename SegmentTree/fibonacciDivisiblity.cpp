// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<vector<int>> trans = {{0, 1}, {1, 1}};

vector<vector<int>> mulMat(vector<vector<int>> a, vector<vector<int>> b)
{
  vector<vector<int>> c(2, vector<int>(2, 0));
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      c[i][j] = 0;
      for (int x = 0; x < 2; x++)
      {
        c[i][j] += a[i][x] * b[x][j];
        c[i][j] %= mod;
      }
    }
  }
  return c;
}

vector<vector<int>> powerMat(vector<vector<int>> t, int p)
{
  if (p == 1)
    return t;
  vector<vector<int>> temp = powerMat(t, p / 2);
  temp = mulMat(temp, temp);

  if (p & 1)
  {
    temp = mulMat(t, temp);
  }
  return temp;
}

int fibo(int n)
{
  if (n <= 2)
    return 1;
  //trans pow n-2
  vector<vector<int>> powTrans = powerMat(trans, n - 2);
  return (powTrans[1][0] + powTrans[1][1]) % mod;
}

int gcd(int a, int b)
{
  if (b > a)
    swap(a, b);
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void buildTree(vector<int> &a, int s, int e, vector<int> &tree, int index)
{
  if (s == e)
  {
    tree[index] = a[s];
    return;
  }

  int mid = (s + e) / 2;
  buildTree(a, s, mid, tree, 2 * index);
  buildTree(a, mid + 1, e, tree, 2 * index + 1);
  tree[index] = gcd(tree[2 * index], tree[2 * index + 1]);
}

int query(vector<int> &tree, int ss, int se, int qs, int qe, int index)
{
  //out of bound
  if (qs > se or qe < ss)
    return 0;

  //complete overlap
  if (ss >= qs and se <= qe)
    return tree[index];

  //partial
  int mid = (ss + se) / 2;
  int left = query(tree, ss, mid, qs, qe, 2 * index);
  int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
  return gcd(left, right);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  vector<int> tree(4 * n + 1, 1);
  buildTree(a, 1, n, tree, 1);

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    int temp = query(tree, 1, n, l, r, 1);
    if (temp == 0)
      temp = 1;
    cout << fibo(temp) << endl;
  }

  return 0;
}
