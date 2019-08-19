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
 
const int N = 2e5 + 10;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;
 
int res[N];
bool use[N];
 
int main() {
    LL n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO\n";
    } else {
        for (int now = 1, pos = 0; now <= n * 2; ++now) {
            res[pos] = now;
            if (pos & 1) {
                pos = (pos + 1) % (n * 2);
            } else {
                pos = (pos + n) % (n * 2);
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n * 2; ++i) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}