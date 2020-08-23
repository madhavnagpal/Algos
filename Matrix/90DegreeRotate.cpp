#include <bits/stdc++.h>
using namespace std;

const int N = 4;

void rotateMatrix(int mat[N][N])
{
  //each layer in terms of squares
  for (int x = 0; x < N / 2; x++)
  {
    for (int y = x; y < N - x - 1; y++)
    {
      int temp = mat[x][y];
      mat[x][y] = mat[y][N - x - 1];
      mat[y][N - x - 1] = mat[N - x - 1][N - y - 1];
      mat[N - x - 1][N - y - 1] = mat[N - y - 1][x];
      mat[N - y - 1][x] = temp;
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int mat[N][N] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};

  cout << "Matrix before rotation" << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  rotateMatrix(mat);

  cout << "Matrix after rotation" << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}