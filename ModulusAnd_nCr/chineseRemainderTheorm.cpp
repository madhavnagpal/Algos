// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

void init();

pair<int, int> modInv(int a, int b, int mod) {
	if (b == 0)
		return {1, 0};
	pair<int, int> p = modInv(b, a % b, mod);
	int x = p.second;
	int y = p.first - (a / b) * p.second;
	x = (x + mod) % mod;
	y = (y % mod) % mod;
	return {x, y};
}

//chinese remainder theorem
int32_t main() {
	init();

	int n;
	cin >> n;

	vector<int> num(n), rem(n);
	int product = 1;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		product *= num[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> rem[i];
	}

	int x = 0;

	for (int i = 0; i < n; i++) {
		int pp = product / num[i];
		pair<int, int> p = modInv(pp, num[i], num[i]);

		int inv = p.first;
		int temp = (pp * inv * rem[i]) % product;

		x = (x + temp + product) % product;
	}
	cout << x << endl;


	return 0;
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

