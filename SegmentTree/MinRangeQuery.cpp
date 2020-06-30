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

void buildTree(int *a, int s, int e, int *tree, int index)
{
  if (s == e)
  {
    tree[index] = a[s];
    return;
  }
  // recc
  int mid = (s + e) / 2;
  buildTree(a, s, mid, tree, 2 * index);
  buildTree(a, mid + 1, e, tree, 2 * index + 1);
  tree[index] = min(tree[2 * index], tree[2 * index + 1]);
  return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
  //complete overlap
  if (ss >= qs and se <= qe)
  {
    return tree[index];
  }
  // no overlap
  if (qe < ss or qs > se)
  {
    return INT_MAX;
  }
  //partial overlap
  int mid = (ss + se) / 2;
  int left = query(tree, ss, mid, qs, qe, 2 * index);
  int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
  return min(left, right);
}

void updateNode(int *tree, int ss, int se, int i, int increment, int index)
{
  //no overlap
  if (i > se or i < ss)
    return;
  // leaf node
  if (ss == se)
  {
    tree[index] += increment;
    return;
  }
  // otherwise
  int mid = (ss + se) / 2;
  updateNode(tree, ss, mid, i, increment, 2 * index);
  updateNode(tree, mid + 1, se, i, increment, 2 * index + 1);
  tree[index] = min(tree[2 * index], tree[2 * index + 1]);
  return;
}

void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
  //out of bounds
  if (r < ss or l > se)
    return;
  //leaf node
  if (ss == se)
  {
    tree[index] += inc;
    return;
  }
  //recc
  int mid = (ss + se) / 2;
  updateRange(tree, ss, mid, l, r, inc, 2 * index);
  updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);
  tree[index] = min(tree[2 * index], tree[2 * index + 1]);
  return;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int a[] = {1, 3, 2, -5, 6, 4};
  int n = sizeof(a) / sizeof(a[0]);
  int *tree = new int[4 * n + 1];

  buildTree(a, 0, n - 1, tree, 1);
  updateNode(tree, 0, n - 1, 3, 10, 1);
  updateRange(tree, 0, n - 1, 3, 5, 2, 1);

  int q;
  cin >> q;

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << query(tree, 0, n - 1, l, r, 1) << endl;
  }

  return 0;
}
