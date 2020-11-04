#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    string str = "1";

    for (int mult = 2; mult <= n; mult++)
    {
        int carry = 0;

        for (int curr = 0; curr < str.size(); curr++)
        {
            int num = str[curr] - '0';
            int product = (num * mult) + carry;
            num = product % 10;
            carry = product / 10;
            str[curr] = '0' + num;
        }

        while (carry >= 1)
        {
            str += '0' + carry % 10;
            carry /= 10;
        }
    }

    reverse(str.begin(), str.end());

    cout << str << endl;

    return 0;
}