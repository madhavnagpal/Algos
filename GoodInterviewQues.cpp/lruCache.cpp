// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

//Least Recent Used Cache Implementation

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class least_recent_used_cache {
public:
    list<int> cache;
    map<int, list<int>::iterator> h;
    int max_size, curr_size;

    least_recent_used_cache(int n) {
        max_size = n;
        curr_size = 0;
    }

    void insert_in_cache(int n) {
        //whether number is already in cache or not
        if (h.find(n) == h.end()) {
            if (curr_size == max_size) {
                int last = cache.back();
                h.erase(last);
                cache.pop_back();
                curr_size--;
            }
        }
        else {
            cache.erase(h[n]);
        }
        cache.push_front(n);
        h[n] = cache.begin();
        curr_size++;
    }

    void print() {
        cout << "cache is:";
        for (auto x : cache) {
            cout << x << " ";
        }
        cout << endl;
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

    least_recent_used_cache cache1(4);
    cache1.insert_in_cache(1);
    cache1.insert_in_cache(2);
    cache1.insert_in_cache(3);
    cache1.insert_in_cache(4);
    cache1.print();

    cache1.insert_in_cache(2);
    cache1.insert_in_cache(2);

    cache1.print();

    cache1.insert_in_cache(3);

    cache1.print();

    return 0;
}
