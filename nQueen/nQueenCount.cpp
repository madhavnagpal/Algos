// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int ans, done;

void solve(int rowMask, int ld, int rd) {
	if (rowMask == done) {
		ans++;
		return;
	}
	int safe = done & (~(rowMask | ld | rd));
	while (safe) {
		int p = safe & (-safe);
		safe -= p;
		solve(rowMask | p, (ld | p) << 1, (rd | p) >> 1);
	}
}

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	done = (1 << n) - 1;
	ans = 0;

	solve(0, 0, 0);
	cout << ans << endl;

	return 0;
}

