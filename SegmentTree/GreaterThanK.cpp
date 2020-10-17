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

void merge(vector<int> &c, vector<int> &a, vector<int> &b)
{
  int i = 0, j = 0, n1 = a.size(), n2 = b.size();
  c.clear();
  c.reserve(n1 + n2);

  while (i < n1 && j < n2)
  {
    if (a[i] < b[j])
    {
      c.push_back(a[i++]);
    }
    else
    {
      c.push_back(b[j++]);
    }
  }
  while (i < n1)
  {
    c.push_back(a[i++]);
  }
  while (j < n2)
  {
    c.push_back(b[j++]);
  }
}

void buildTree(vector<int> &a, int s, int e, vector<vector<int>> &tree, int index)
{
  if (s == e)
  {
    tree[index].clear();
    tree[index].push_back(a[s]);
    return;
  }
  int mid = (s + e) / 2;
  buildTree(a, s, mid, tree, 2 * index);
  buildTree(a, mid + 1, e, tree, 2 * index + 1);
  //merge two vectors into tree[index]
  merge(tree[index], tree[2 * index], tree[2 * index + 1]);
}

int query(vector<vector<int>> &tree, int ss, int se, int qs, int qe, int k, int index)
{
  if (qs > se or qe < ss)
    return 0;
  if (ss >= qs and se <= qe)
  {
    auto it = lower_bound(tree[index].begin(), tree[index].end(), k);
    return tree[index].end() - it;
  }
  //partial
  int mid = (ss + se) / 2;
  int left = query(tree, ss, mid, qs, qe, k, 2 * index);
  int right = query(tree, mid + 1, se, qs, qe, k, 2 * index + 1);
  return left + right;
}

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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  vector<vector<int>> tree(4 * n + 1, vector<int>(1));

  buildTree(a, 1, n, tree, 1);

  int q;
  cin >> q;

  while (q--)
  {
    int l, r, k;
    cin >> l >> r >> k;
    cout << query(tree, 1, n, l, r, k, 1) << endl;
  }

  return 0;
}
