#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size(), idx = 0;

    while (idx < n) {
        int start = idx, num_of_words = 0, num_of_chars = 0;
        while (idx < n and num_of_words + num_of_chars + words[idx].size() <= maxWidth) {
            num_of_words++, num_of_chars += words[idx].size(), idx++;
        }
        string str = words[start];

        if (idx >= n or num_of_words == 1) {
            for (int i = start + 1; i < idx and i < n; i++) {
                str += " ";
                str += words[i];
            }
            int len = maxWidth - str.size();
            if (len > 0) {
                string temp(len, ' ');
                str += temp;
            }
        }
        else {
            int spaces_for_all = (maxWidth - num_of_chars) / (num_of_words - 1);
            string temp(spaces_for_all, ' ');
            int extra = (maxWidth - num_of_chars) % (num_of_words - 1);

            for (int i = start + 1; i < idx and i < n; i++) {
                str += temp;
                if (extra > 0) {
                    str += " ";
                    extra--;
                }
                str += words[i];
            }
        }
        result.push_back(str);
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<string> a ={ "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
        "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"
    };
    vector<string> result = fullJustify(a, 20);

    for (auto str : result) {
        cout << str << endl;
    }

    return 0;
}