// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n;

	vector<int> jump(101, 0);
	for (int i = 0; i < n; i++) {
		//ladder
		int u, v;
		cin >> u >> v;
		jump[u] += v - u ;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		//snake
		int head, tail;
		cin >> head >> tail;
		jump[head] += tail - head;
	}

	vector<int> graph[101];

	for (int i = 1; i < 100; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int j = i + dice;
			j += jump[j];
			if (j <= 100) {
				graph[i].push_back(j);
			}
		}
	}

	vector<int> moves(101, -1);
	moves[1] = 0;

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto child : graph[curr]) {
			if (moves[child] == -1) {
				//unvisited
				moves[child] = moves[curr] + 1;
				q.push(child);
			}
		}
	}

	cout << moves[100] << endl;
}

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

	for (int i = 1; i <= test; i++) {
		solve();
	}

	return 0;
}
