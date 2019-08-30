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
 
LL a[111];
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    LL ans = INFLL;
    for (int i = 1; i <= n; ++i) {
        LL now = 0;
        for (int j = 1; j <= n; ++j) {
            LL dist = abs(a[i] - a[j]);
            LL cost = (dist % 2 != 0);
            now += cost;
        }
        ans = min(ans, now);
    }
    cout << ans;
    return 0;
}