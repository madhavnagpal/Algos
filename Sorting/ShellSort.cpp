#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr) {
	int n = arr.size();

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int curr = gap; curr < n; curr++) {
			// let currVal - is the value to place at the right positon
			// performing gapped insertion sort
			int currVal = arr[curr], pos = curr;
			for (; pos >= gap and arr[pos - gap] > currVal; pos -= gap) {
				arr[pos] = arr[pos - gap];
			}
			arr[pos] = currVal;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr = {55, -20, 101, 1, 3, 2};

	shellSort(arr);

	cout << "After sorting arr becomes: ";
	for (int curr : arr) {
		cout << curr << " ";
	}
	cout << endl;

	return 0;
}