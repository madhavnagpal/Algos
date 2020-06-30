// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> PBDS;
const int N = 8e5 + 5, mod = 1e9 + 7;

int lazy[N] = {0};

void RangeUpdateLazy(int *tree, int ss, int se, int l, int r, int inc, int index)
{
	//resolve lazy value first
	if (lazy[index] != 0)
	{
		tree[index] += lazy[index];
		//for non leaf node propagate lazy value
		if (ss != se)
		{
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}

	//no overlap
	if (ss > r or l > se)
		return;
	//complete overlap
	if (ss >= l and se <= r)
	{
		tree[index] += inc;
		//for non leaf node propagate lazy value
		if (ss != se)
		{
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}
		return;
	}
	//partial overlap
	int mid = (ss + se) / 2;
	RangeUpdateLazy(tree, ss, mid, l, r, inc, 2 * index);
	RangeUpdateLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index)
{
	//resolve lazy value
	if (lazy[index] != 0)
	{
		tree[index] += lazy[index];
		if (ss != se)
		{
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	//out of range
	if (ss > qe or se < qs)
		return INT_MAX;
	// complete overlap
	if (ss >= qs and se <= qe) {
		return tree[index];
	}
	//partial overlap
	int mid = (ss + se) / 2;
	int left = queryLazy(tree, ss, mid, qs, qe, 2 * index);
	int right = queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return min(left, right);
}

void buildTree(int *a, int s, int e, int *tree, int index)
{
	//leaf
	if (s == e) {
		tree[index] = a[s];
		return;
	}
	//recc

	int mid = (s + e) / 2;
	buildTree(a, s, mid, tree, 2 * index);
	buildTree(a, mid + 1, e, tree, 2 * index + 1);
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
	RangeUpdateLazy(tree, 0, n - 1, 3, 4, 2, 1);
	RangeUpdateLazy(tree, 0, n - 1, 0, 1, 1, 1);
	cout << " [0-5]:" << queryLazy(tree, 0, n - 1, 0, n - 1, 1) << endl;
	cout << " [0-2]:" << queryLazy(tree, 0, n - 1, 0, 2, 1) << endl;
	cout << " [4-5]:" << queryLazy(tree, 0, n - 1, 4, n - 1, 1) << endl;
	cout << " [2-3]:" << queryLazy(tree, 0, n - 1, 2, 3, 1) << endl;

	return 0;
}
