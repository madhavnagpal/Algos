// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

string multiply(string num1, string num2)
{
  if (num1 == "0" or num2 == "0")
    return "0";
  int n1 = num1.size(), n2 = num2.size();
  vector<int> res(n1 + n2, 0);

  int i_n1 = 0, i_n2 = 0;

  for (int i = n1 - 1; i >= 0; i--)
  {
    i_n2 = 0;
    int carry = 0;
    int digit1 = num1[i] - '0';

    for (int j = n2 - 1; j >= 0; j--)
    {
      int digit2 = num2[j] - '0';
      int sum = digit2 * digit1 + carry + res[i_n2 + i_n1];
      carry = sum / 10;
      res[i_n2 + i_n1] = sum % 10;
      i_n2++;
    }
    if (carry > 0)
      res[i_n1 + i_n2] += carry;
    i_n1++;
  }
  int i = n1 + n2 - 1;
  while (i >= 0 and res[i] < 1)
    i--;

  string s = "";
  while (i >= 0)
    s += std::to_string(res[i--]);
  return s;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout << multiply("123", "12") << endl;

  return 0;
}
