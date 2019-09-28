#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;
const LL MOD = 1e9 + 7;

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

int main() {
    int n, k;
    vector<LL> v;
    map<LL, int> cnt;
    set<LL> used;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        LL x;
        cin >> x;
        ++cnt[x];
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        LL val = v[i];
        if (used.count(val * k)) continue;
        if (val % k != 0) {
            ans += cnt[val];
            used.insert(val);
        } else {
            int to = val / k;
            if (cnt.count(to) == 0 || cnt[to] <= cnt[val]) {
                ans += cnt[val];
                used.insert(val);
            }
        }
        show(val, ans);
    }
    cout << ans << '\n';
    return 0;
}