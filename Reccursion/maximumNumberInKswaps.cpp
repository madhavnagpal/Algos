// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

void solve(string str, int curr, int k, string &maximum) {
    if (k < 1)
        return;
    char max_ch = str[curr];

    for (int i = curr + 1; i < str.size(); i++) {
        max_ch = max(max_ch, str[i]);
    }

    if (max_ch != str[curr])
        k--;

    for (int j = curr; j < str.size(); j++) {
        if (str[j] == max_ch) {
            swap(str[j], str[curr]);
            maximum = max(str, maximum);
            solve(str, curr + 1, k, maximum);
            swap(str[j], str[curr]);
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
    int test;
    cin >> test;

    for (int i = 1; i <= test; i++) {
        int k;
        cin >> k;

        string str, maximum;
        cin >> str;
        maximum = str;

        solve(str, 0, k, maximum);

        cout << maximum << endl;
    }

    return 0;
}
