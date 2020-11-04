#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, int start, int middle, int end)
{
	long long cross_inversions = 0;
	int len = end - start + 1;
	vector<int> temp(len);
	int one = start, two = middle + 1, curr = 0;

	while (one <= middle and two <= end)
	{
		//got inversions
		if (arr[one] > arr[two])
		{
			cross_inversions += middle - one + 1;
			temp[curr++] = arr[two++];
		}
		else
		{
			temp[curr++] = arr[one++];
		}
	}

	while (one <= middle)
	{
		temp[curr++] = arr[one++];
	}
	while (two <= end)
	{
		temp[curr++] = arr[two++];
	}

	curr = start;
	for (int i = 0; i < len; i++)
	{
		arr[curr++] = temp[i];
	}
	return cross_inversions;
}

long long count_inversions(vector<int> &arr, int start, int end)
{
	if (start >= end)
		return 0;
	int middle = (start + end) / 2;

	long long left = count_inversions(arr, start, middle);
	long long right = count_inversions(arr, middle + 1, end);
	long long cross_inversions = merge(arr, start, middle, end);
	return left + right + cross_inversions;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << count_inversions(arr, 0, n - 1) << endl;
	}

	return 0;
}