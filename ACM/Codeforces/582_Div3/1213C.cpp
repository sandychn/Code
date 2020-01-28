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

int main() {
    LL last[10];
    int q;
    cin >> q;
    while (q--) {
        LL n, m;
        cin >> n >> m;
        LL time = n / m, sum = 0;
        for (int i = 0; i < 10; ++i) {
            last[i] = (m % 10 * i) % 10;
            sum += last[i];
        }
        LL ans = (time / 10) * sum;
        // show(ans);
        for (int i = 1; i <= time % 10; ++i) {
            ans += last[i];
        }
        cout << ans << endl;
    }
    return 0;
}