// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int allColors[N] = {0};
int tree[4 * N + 1] = {0};
int lazy[4 * N + 1] = {0};

void upadateRange(int ss, int se, int qs, int qe, int color, int index) {

	//resolve lazy
	if (lazy[index] != 0) {
		tree[index] = lazy[index];
		if (ss != se) {
			lazy[2 * index] = lazy[index];
			lazy[2 * index + 1] = lazy[index];
		}
		lazy[index] = 0;
	}

	//out of range
	if (qs > se or qe < ss)
		return;

	//complete overlap
	if (ss >= qs and se <= qe) {
		tree[index] = color;
		if (ss != se) {
			lazy[2 * index] = color;
			lazy[2 * index + 1] = color;
		}
		return;
	}

	//partial
	int mid = (ss + se) / 2;
	upadateRange(ss, mid, qs, qe, color, 2 * index);
	upadateRange(mid + 1, se, qs, qe, color, 2 * index + 1);
	tree[index] = -1;
}

void build(int ss, int se, int index) {
	//resolve lazy
	if (lazy[index] != 0) {
		tree[index] = lazy[index];
		if (ss != se) {
			lazy[2 * index] = lazy[index];
			lazy[2 * index + 1] = lazy[index];
		}
		lazy[index] = 0;
	}

	if (tree[index] == -1) {
		int mid = (ss + se) / 2;
		build(ss, mid, 2 * index);
		build(mid + 1, se, 2 * index + 1);
	} else {
		for (int i = ss; i <= se; i++) {
			allColors[i] = tree[index];
		}
	}
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

	while (q--) {
		int l, r, c;
		cin >> l >> r >> c;
		upadateRange(1, n, l, r, c, 1);
	}

	build(1, n, 1);

	for (int i = 1; i <= n; i++) {
		cout << allColors[i] << endl;
	}
	return 0;
}
