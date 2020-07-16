// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5 + 5, mod = 1e9 + 7;

class lru
{
  list<int> dq;
  map<int, list<int>::iterator> h;
  int csize;

public:
  lru(int n)
  {
    csize = n;
  }
  void refer(int x)
  {

    if (h[x] == h.end())
    {

      if (dq.size() == csize)
      {
        int last = dq.back();
        h.erase(last);
        dq.pop_back();
      }
    }
    else
    {
      dq.erase(h[x]);
    }
    dq.push_front(x);
    h[x] = dq.begin();
  }
};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  return 0;
}
