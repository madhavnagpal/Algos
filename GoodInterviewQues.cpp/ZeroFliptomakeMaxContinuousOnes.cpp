// C++ program to find positions of zeroes flipping which
// produces maximum number of xonsecutive 1's
#include <bits/stdc++.h>
using namespace std;

void findZeroes(int a[], int n, int m)
{
  int window_left = 0, window_right = 0;
  int longest_window_size = 0, zero_count = 0, best_left = 0;

  while (window_right < n)
  {
    if (zero_count <= m)
    {
      if (!a[window_right])
        zero_count++;
      window_right++;
    }
    if (zero_count > m)
    {
      if (!a[window_left])
        zero_count--;
      window_left++;
    }
    int new_window_size = window_right - window_left;
    if (new_window_size > longest_window_size)
    {
      longest_window_size = new_window_size;
      best_left = window_left;
    }
  }

  for (int i = 0; i < longest_window_size; i++)
  {
    if (!a[i + best_left])
      cout << i + best_left << " ";
  }
}

// Driver program
int main()
{
  int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
  int m = 2;
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Indexes of zeroes to be flipped are ";
  findZeroes(arr, n, m);
  return 0;
}