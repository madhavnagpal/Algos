// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> PBDS;

#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int stringToNum(string str, int n) {
	int ans = 0;

	for (char ch : str) {
		int digit = ch - '0';
		ans = ( ans * 10 + digit ) % n;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	if (n == 0) {
		cout << str << endl;
		return;
	}

	int num = stringToNum(str, n);
	cout << gcd(n, num) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}

