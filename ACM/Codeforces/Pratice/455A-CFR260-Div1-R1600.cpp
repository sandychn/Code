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
const int N = 1e5 + 10;

LL dp[N][2];
int cnt[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    LL ans = 0;
    for (int i = 1; i < N; ++i) {
        LL val = 1LL * cnt[i] * i;
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max((i == 1 ? 0 : dp[i - 2][1]), dp[i - 1][0]) + val;
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    return 0;
}