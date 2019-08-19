#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

__gnu_pbds::cc_hash_table<string, __gnu_pbds::null_type> mp;

void update(string &s, int pos) {
    int l = pos, r = pos, cnt = 1;
    char now = s[l];
    while (true) {
        while (l && s[l - 1] == now) --l, ++cnt;
        while (r < (int)s.size() && s[r + 1] == now) ++r, ++cnt;
        if (cnt >= 3) {
            s.erase(s.begin() + l, s.begin() + r + 1);
            --l;
            r = l + 1;
            if (l < 0 || r >= (int)s.size() || s[l] != s[r]) break;
            cnt = 2;
            now = s[l];
        } else {
            break;
        }
    }
}

int solve(int n, string &original) {
    mp.clear();
    queue<pair<string, int>> q;
    mp.insert(original);
    string s;
    for (q.emplace(original, 0); !q.empty(); q.pop()) {
        auto &now = q.front();
        if (now.second >= 4) {
            continue;
        }
        int len = now.first.size();
        for (int i = 0; i <= len; ++i) {
            for (char ch = '1'; ch <= '3'; ++ch) {
                s = now.first;
                s.insert(s.begin() + i, ch);
                update(s, i);
                if (s.empty()) return now.second + 1;
                if (mp.find(s) != mp.end()) continue;
                mp.insert(s);
                q.emplace(s, now.second + 1);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}