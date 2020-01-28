#include <bits/stdc++.h>
 
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
 
const int INF = 0x3F3F3F3F;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;
 
const int N = 100 * 4 + 50;
const int MAX = 1e4 + 10;
 
int a[N];
 
 
bool solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n * 4; ++i) {
        int x;
        cin >> x;
        ++mp[x];
    }
    LL area = mp.begin()->first * (--mp.end())->first;
    while (!mp.empty()) {
        if (mp.size() == 1) {
            if (mp.begin()->first * mp.begin()->first != area)
                return false;
            return mp.begin()->second % 4 == 0;
        }
        if (mp.begin()->first * (--mp.end())->first != area)
            return false;
        int cnt1 = mp.begin()->second, cnt2 = (--mp.end())->second;
        if (cnt1 != cnt2) return false;
        if (cnt1 & 1) return false;
        if (cnt2 & 1) return false;
        mp.erase(mp.begin());
        mp.erase(--mp.end());
    }
    return true;
}
 
int main() {
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}