// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

//multi source bfs

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 505;

vector<pair<int, int>> graph[M][M];
int a[M][M], visited[M][M], n, m, maxi;

void solve()
{
  cin >> n >> m;
  maxi = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> a[i][j];
      visited[i][j] = 0;
      maxi = max(maxi, a[i][j]);
      graph[i][j].clear();
    }
  }

  int di[] = {0, 0, 1, 1, 1, -1, -1, -1};
  int dj[] = {1, -1, 0, 1, -1, 0, 1, -1};

  //add edges and get maxi's in queue
  queue<pair<int, int>> q;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (a[i][j] == maxi)
      {
        q.push({i, j});
        visited[i][j] = 1;
      }
      for (int k = 0; k < 8; k++)
      {
        int ii = i + di[k], jj = j + dj[k];
        if (ii >= 1 and ii <= n and jj >= 1 and jj <= m)
          graph[i][j].push_back({ii, jj});
      }
    }
  }

  int timer = 0;

  while (!q.empty())
  {
    queue<pair<int, int>> q2;

    while (!q.empty())
    {
      auto p = q.front();
      q.pop();
      for (auto child : graph[p.first][p.second])
      {
        if (!visited[child.first][child.second])
        {
          q2.push(child);
          visited[child.first][child.second] = 1;
        }
      }
    }
    q = q2;
    timer++;
  }
  cout << timer - 1 << endl;
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

  for (int i = 1; i <= test; i++)
  {
    solve();
  }

  return 0;
}
