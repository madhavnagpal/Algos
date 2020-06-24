// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<vector<int> > matrix;
int mod = 1e9 + 7;

matrix mulMat(matrix a, matrix b) {
	matrix c(3, vector<int>(3));

	for (int i = 1; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			c[i][j] = 0;
			for (int x = 1; x < 3; x++) {
				c[i][j] += a[i][x] * b[x][j];
				c[i][j] %= mod;
			}
		}
	}
	return c;
}

matrix powMat(matrix x, int p) {
	if (p == 1)
		return x;
	if (p & 1)
		return mulMat(x, powMat(x, p - 1));
	matrix temp = powMat(x, p / 2);
	return mulMat(temp, temp);
}

int fib(int n) {
	vector<int> f1 = { 0, 1, 1};
	if (n < 3)
		return f1[n];

	matrix trans, powTrans;
	trans = { {}, {0, 0, 1}, {0, 1, 1}};

	powTrans = powMat(trans, n - 2);

	int sum = powTrans[2][1] + powTrans[2][2];
	return sum % mod;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);

	int test;
	cin >> test;

	while (test--) {
		int n;
		cin >> n;

		cout << fib(n) << endl;
	}

	return 0;
}

