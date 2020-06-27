// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
int n, c;

bool check(set<int> &s, int first, int k) {
	int curr = first;
	for (int i = 1; i < c; i++ ) {
		int key = curr + k;
		auto it = s.lower_bound(key);
		if (it == s.end())
			return false;
		curr = *it;
	}
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> c;

	set<int> mySet;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		mySet.insert(num);
	}
	int last = *(mySet.rbegin());
	int first = *(mySet.begin());
	num = last - first;

	int s = 0, e = num;
	int ans = 0;

	while (s <= e) {
		int mid = (s + e) / 2;
		//check if it is possible to put cows at dis of mid
		bool poss = check(mySet, first, mid);
		if (poss) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}

	}
	cout << ans << endl;


	return 0;
}
