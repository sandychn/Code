#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

map<int, pair<LL, priority_queue<int>>> mp;

int main() {
    ios::sync_with_stdio(false);
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x) {
            mp[x].first += cnt;
            auto it = mp.find(x);
            it->second.second.push(cnt);
            if ((int)it->second.second.size() > n) {
                it->second.first -= it->second.second.top();
                it->second.second.pop();
            }
            x /= 2;
            ++cnt;
        }
        mp[x].first += cnt;
        auto it = mp.find(x);
        it->second.second.push(cnt);
        if ((int)it->second.second.size() > n) {
            it->second.first -= it->second.second.top();
            it->second.second.pop();
        }
    }
    LL ans = INFLL;
    for (auto val : mp) {
        if ((int)val.second.second.size() == n) {
            ans = min(ans, val.second.first);
        }
        // cout << val.first << ' ' << val.second.first << ' ' << val.second.second << endl;
    }
    cout << ans;
    return 0;
}