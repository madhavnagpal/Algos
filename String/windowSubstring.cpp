#include <bits/stdc++.h>
using namespace std;

string findSmallestWindow(string str, string pat) {
    int len1 = str.size(),
        len2 = pat.size();
    if (len2 > len1)
        return "";

    map<char, int> window, pattern;
    for (int i = 0; i < len2; i++) {
        pattern[pat[i]]++;
    }

    int counter = 0, start = 0, start_index = -1, window_size = INT_MAX;

    for (int i = 0; i < len1; i++) {
        window[str[i]]++;

        if (pattern[str[i]] > 0 and window[str[i]] <= pattern[str[i]])
            counter++;

        //pattern detected
        if (counter == len2) {

            while (window[str[start]] > pattern[str[start]]
                || pattern[str[start]] == 0)
            {
                if (window[str[start]] > pattern[str[start]])
                    window[str[start]]--;
                start++;
            }

            int temp_window_size = i - start + 1;

            if (window_size > temp_window_size) {
                start_index = start;
                window_size = temp_window_size;
            }
        }
    }
    if (start_index == -1)
        return "";
    return str.substr(start_index, window_size);

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cout << findSmallestWindow("abcdefgohijkldego", "ego") << endl;
    return 0;
}