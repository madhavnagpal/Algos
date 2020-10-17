// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> graph[N];
int n, m;
int discovery_time[N], lowest_time[N], timer = 0;
set<int> articulation_points;
vector<pair<int, int>> articulation_bridges;

void dfs(int curr, int parent)
{
  discovery_time[curr] = lowest_time[curr] = ++timer;
  int num_of_childs = 0;

  for (auto child : graph[curr])
  {
    //not visited child
    if (discovery_time[child] == 0)
    {
      dfs(child, curr);
      lowest_time[curr] = min(lowest_time[curr], lowest_time[child]);
      num_of_childs++;
      //articulation point
      if (parent != 0 and lowest_time[child] >= discovery_time[curr])
      {
        articulation_points.insert(curr);
      }

      //articulation bridges
      if (lowest_time[child] > discovery_time[curr])
      {
        articulation_bridges.pb({curr, child});
      }
    }
    else if (child != parent)
    {
      //back edge
      lowest_time[curr] = min(lowest_time[curr], discovery_time[child]);
    }
  }
  // for root to be a articulation point
  if (parent == 0)
  {
    if (num_of_childs >= 2)
      articulation_points.insert(curr);
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
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(1, 0);

  cout << "printing articulation points" << endl;
  for (auto x : articulation_points)
  {
    cout << x << endl;
  }

  cout << "printing articulation bridges" << endl;
  for (auto p : articulation_bridges)
  {
    cout << p.first << "-->" << p.second << endl;
  }

  return 0;
}
