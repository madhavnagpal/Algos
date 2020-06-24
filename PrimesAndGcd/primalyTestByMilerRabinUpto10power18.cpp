// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;

#define int long long
void init();

int multiply(int a, int b, int m) {
	int ans = 0;
	while (b) {
		if (b & 1)
			ans += a;
		b /= 2;
		a *= 2;
		a %= m;
		ans %= m;
	}
	return ans;
}

int power(int a, int b, int m) {
	if (b == 0)
		return 1;
	int temp = power(a, b / 2, m);
	temp = multiply(temp, temp, m);
	if (b & 1)
		return multiply(a, temp, m);
	return temp;
}

bool isPrime(int n) {

	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	// n is odd >2 therefore n-1 is even
	int d = n - 1, s = 0;

	while ( d % 2 == 0) {
		d /= 2;
		s++;
	}

	vector<int> a({2, 3, 5, 7, 11, 13, 17, 19, 23});

	for (int i = 0; i < a.size(); i++) {

		if (a[i] > n - 2) continue;
		int ad = power(a[i], d, n);
		if (ad % n == 1) continue;

		bool prime = false;

		for (int j = 0; j < s; j++) {
			int r = power(2, j, n);
			int ard = power(ad, r, n);
			if (ard % n == n - 1) {
				prime = true;
				break;
			}
		}
		if (!prime) return false;
	}
	return true;

}

int32_t main() {
	init();

	int test;
	cin >> test;

	while (test--) {
		int n;
		cin >> n;

		if (isPrime(n))
			cout << "prime" << endl;
		else
			cout << "not prime" << endl;
	}
	return 0;
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
#endif
}

