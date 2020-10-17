#include <bits/stdc++.h>
using namespace std;

void shuffle(vector<int>& arr) {
	srand(time(0));
	int len = arr.size();

	for (int i = len - 1; i > 0; i--) {
		int num = (rand()) % i;
		swap(arr[i], arr[num]);
	}
}

int partition(vector<int>& arr, int start, int end) {
	int currPos = start, smallPos = start;
	while (currPos < end) {
		if (arr[currPos] < arr[end]) {
			swap(arr[smallPos++], arr[currPos]);
		}
		currPos++;
	}
	swap(arr[smallPos], arr[end]);
	return smallPos;
}

void quickSort(vector<int>& arr, int start, int end) {
	if (start >= end)
		return;
	int posAfterPartition = partition(arr, start, end);
	quickSort(arr, start, posAfterPartition - 1);
	quickSort(arr, posAfterPartition + 1, end);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	shuffle(arr);
	cout << "after shuffling:";
	for (int curr : arr) {
		cout << curr << " ";
	}
	cout << endl;

	quickSort(arr, 0, n - 1);

	cout << "After sorting array becomes:";
	for (int curr : arr) {
		cout << curr << " ";
	}
	cout << endl;

	return 0;
}