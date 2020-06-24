// I am Nothing , You Are Nothing
// Jai Shree Krishna

//inversion count
#include<bits/stdc++.h>
using namespace std;

int cross_count(vector<int> &a, int s, int mid, int e) {
	int i = s, j = mid + 1, k = s;
	vector<int> temp(100000);

	int cnt = 0;
	while (i <= mid && j <= e) {
		if (a[i] > a[j]) {
			cnt += mid - i + 1;
			temp[k++] = a[j++];
		} else {
			temp[k++] = a[i++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}
	return cnt;
}

int inversion_count(vector<int> &a, int s, int e) {
	if (s >= e) {
		return 0;
	}
	int mid = (s + e) / 2;
	int x = inversion_count(a, s, mid);
	int y = inversion_count(a, mid + 1, e);
	int z = cross_count(a, s, mid, e);
	return x + y + z;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Inversion Count:" << inversion_count(a, 0, n - 1) << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}

