// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

// Travelling Salesman Problem

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

/*
	Essence of Tsp is we have edge b/w every pair of cities and we have to
	complete the hamiltonian cycle i.e we have to reach back to src node
	with minimum weight,
	so we store edges in 2-d array instead of adjacency matrix
	By optimising to Dp we got O((2^n)*n)
*/

int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

int n = 4;
vector<vector<int>> dp(1 << n, vector<int>(n, -1));
int VISITED_ALL = (1 << 4) - 1;

int tsp(int mask, int pos)
{

  // visited all so completing hamiltonian cycle by reaching back to src
  if (mask == VISITED_ALL)
    return dist[pos][0];

  if (dp[mask][pos] != -1)
    return dp[mask][pos];

  int ans = INT_MAX;

  for (int city = 0; city < n; city++)
  {
    //city not visited
    if ((mask & (1 << city)) == 0)
    {
      int temp = dist[pos][city] + tsp(mask | (1 << city), city);
      ans = min(temp, ans);
    }
  }
  return dp[mask][pos] = ans;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout << tsp(1, 0) << endl;
  return 0;
}
