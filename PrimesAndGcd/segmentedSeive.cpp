// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> arr(N, 1);
vector<int> primes;

void seive()
{
	arr[0] = arr[1] = 0;

	for (int i = 2; i < N; i++)
	{
		if (arr[i])
		{
			primes.push_back(i);
			for (int j = i + i; j < N; j += i)
			{
				arr[j] = 0;
			}
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);

	seive();
	int test;
	cin >> test;

	while (test--) {
		int a, b;
		cin >> a >> b;

		if (b < N) {
			for (int i = a; i <= b; i++) {
				if (arr[i])
					cout << i << endl;
			}
		} else {

			//time for segmented seive
			vector<int> p(b - a + 1, 1);

			for (int i = 0; primes[i]*primes[i] <= b; i++)
			{
				int start = (a / primes[i]) * primes[i];

				if (primes[i] >= a && primes[i] <= b)
					start = 2 * start;
				if (start < a)
					start += primes[i];

				for (int j = start; j <= b; j += primes[i])
					p[j - a] = 0;
			}

			for (int i = 0; i < b - a + 1; i++) {
				if (p[i])
					cout << i + a << endl;
			}
		}
		cout << endl;
	}
	return 0;
}

