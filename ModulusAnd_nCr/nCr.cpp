// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5, m = 1e9 + 7;

void init();

int mExp(int a, int b) {
	if (b == 0)
		return 1;
	int temp = mExp(a, b / 2);
	temp *= temp;
	temp = (temp + m) % m;
	if (b & 1)
		return (a * temp) % m;
	return temp;
}

int nCr(int n, int r) {

	if (n <= 0 || r < 0)
		return 0;

	if (r == 0 || n == r) {
		return 1;
	}

	int nFac = n, rFac = r,
	    nMrFac = n - r;

	for (int i = 1; i < n; i++) {
		nFac *= i;
		nFac = (nFac + m) % m;
	}
	int nCr = nFac;

	for (int i = 1; i < r; i++) {
		rFac *= i;
		rFac = ( rFac + m) % m;
	}
	// calculating inverse of r! by using fermits little theorem
	int inv = mExp(rFac, m - 2);

	nCr *= inv;
	nCr = ( nCr + m ) % m;

	for (int i = 1; i < (n - r); i++) {
		nMrFac *= i;
		nMrFac = ( nMrFac + m ) % m;
	}
	// calculating inverse of (n-r)! by using fermits little theorem
	inv = mExp(nMrFac, m - 2);

	nCr *= inv;
	nCr = ( nCr + m ) % m;

	return nCr;
}

int32_t main() {
	init();

	int n, r;
	cin >> n >> r;

	cout << nCr(n, r) << endl;

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

