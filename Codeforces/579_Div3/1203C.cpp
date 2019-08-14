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
 
const int N = 4e5 + 50;
 
LL a[N];
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    LL g = a[1];
    for (int i = 2; i <= n; ++i) g = __gcd(g, a[i]);
    show(g);
    LL ans = 1;
    for (LL i = 2; i <= g / i; ++i) {
        if (g % i == 0) {
            LL cnt = 0;
            while (g % i == 0) {
                ++cnt;
                g /= i;
            }
            show(i);
            show(cnt);
            ans *= (cnt + 1);
        }
    }
    if (g != 1) {
        ans *= 2;
    }
    cout << ans;
    return 0;
}