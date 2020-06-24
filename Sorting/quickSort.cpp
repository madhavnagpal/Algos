// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int partition(vector<int> &v, int s, int e) {
	//last as pivot so put end at right position
	int pivot = v[e];
	int i = s - 1, j = s;

	while (j < e) {
		if (v[j] < pivot) {
			swap(v[j], v[++i]);
		}
		j++;
	}
	swap(v[i + 1], v[e]);
	return i + 1;
}

void quickSort(vector<int> &v, int s, int e)
{
	if (s >= e) {
		return;
	}
	int p = partition(v, s, e);
	quickSort(v, s, p - 1);
	quickSort(v, p + 1, e);
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
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	quickSort(v, 0, n - 1);

	cout << "after sort" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}

