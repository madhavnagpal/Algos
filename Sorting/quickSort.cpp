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
const int N = 2e5 + 5, mod = 1e9 + 7;

int a[N] = {0};
int n;

void shuffle() {
	srand(time(NULL));
	for (int i = n - 1; i > 0; i--) {
		int temp = rand() % i;
		swap(a[i], a[temp]);
	}
}

int partition(int s, int e) {
	int pivot = a[e];
	int i = s - 1, j = s;

	while (j < e) {
		if (a[j] < pivot) {
			swap(a[++i], a[j++]);
		} else {
			j++;
		}
	}
	swap(a[e], a[i + 1]);
	return i + 1;
}

void quick_sort(int s, int e) {
	if (s >= e)
		return;
	int p = partition(s, e);
	quick_sort(s, p - 1);
	quick_sort(p + 1, e);
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	shuffle();

	quick_sort(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
