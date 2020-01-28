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

const int MOD = 1000000007;
const int INF = 0x3F3F3F3F;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;

const int N = 105;
const int D = 105;

int dp[2][N][D];  // 边数, 总边权, 最大边权

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    dp[0][0][0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int p = 0; p <= j; ++p) {
                dp[i & 1][j][p] = 0;
            }
        }
        for (int j = 0; j <= n; ++j) {
            for (int p = 0; p <= j; ++p) {
                for (int q = 1; q <= k && j + q <= n; ++q) {  // 新边边权
                    dp[i & 1][j + q][max(p, q)] = (dp[i & 1][j + q][max(p, q)] + dp[(i & 1) ^ 1][j][p]) % MOD;
                }
            }
        }
        for (int p = d; p <= n; ++p) ans = (ans + dp[i & 1][n][p]) % MOD;
    }
    cout << ans;
    return 0;
}