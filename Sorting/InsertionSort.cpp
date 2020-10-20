//inertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
	int size = arr.size();

	for (int curr = 1; curr < size; curr++) {
		//here we know arr form 0 - (curr-1) is sorted
		//we have to put curr card at right position
		int prev = curr - 1;
		while (prev >= 0 and arr[prev] > arr[curr]) {
			swap(arr[prev], arr[curr]);
			prev--, curr--;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr = {4, 2, 5, 6, 1, 9, 9, 10, 12, 11, 0, -22, 55};

	cout << "Before sorting arr is: ";
	for (int curr : arr) {
		cout << curr << " ";
	}
	cout << endl;

	insertionSort(arr);

	cout << "After sorting arr becomes: ";
	for (int curr : arr) {
		cout << curr << " ";
	}
	cout << endl;

	return 0;
}