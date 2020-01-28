#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

LL solve() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    LL res = (LL)v.front() * v.back();
    LL tmp = res;
    vector<int> divisors;
    for (int i = 2; i <= tmp / i; ++i) {
        if (tmp % i == 0) {
            divisors.push_back(i);
            if (1LL * i * i != tmp) divisors.push_back(tmp / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    // for (int i = 0; i < divisors.size(); ++i) cout << divisors[i] << ' ';
    // cout << endl;
    return divisors == v ? res : -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL ans = solve();
        cout << ans << endl;
    }
    return 0;
}