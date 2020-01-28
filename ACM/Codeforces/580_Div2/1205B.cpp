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

const int N = 1e5 + 10;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;

LL dp[N][2];
LL a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0][1] = INF_LL;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i][1] = INF_LL;
        // make a[i] to 1
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(a[i] - 1));
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(a[i] + 1));
        // make a[i] to -1
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + abs(a[i] + 1));
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(a[i] - 1));
    }
    cout << dp[n][0] << endl;
    return 0;
}