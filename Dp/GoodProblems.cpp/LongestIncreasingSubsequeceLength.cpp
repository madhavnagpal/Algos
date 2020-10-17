#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int test;
	cin >> test;

	while (test--) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> lis(n, 1);
		int max_len_poss = 1;

		//sequence ending at index last
		for (int last = 1; last < n; last++) {
			for (int precedent = 0; precedent < last; precedent++) {
				//precedent has smaller value than last elment
				if (a[precedent] < a[last]) {
					int include_preceding_element = lis[precedent] + 1;
					if (include_preceding_element > lis[last]) {
						lis[last] = include_preceding_element;
						max_len_poss = max(max_len_poss, lis[last]);
					}
				}
			}
		}
		cout << max_len_poss << endl;
	}

	return 0;
}