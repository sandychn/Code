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
} _shower;
#else
#define show(x)
#endif

const int N = 1e6 + 10;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;

string s[N][2];
LL a[N], dp[N][2];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], dp[i][0] = dp[i][1] = INF_LL;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i][0] >= s[i - 1][0]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (s[i][0] >= s[i - 1][1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (s[i][1] >= s[i - 1][0]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        }
        if (s[i][1] >= s[i - 1][1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
        }
    }
    LL ans = min(dp[n][0], dp[n][1]);
    cout << (ans == INF_LL ? -1 : ans) << endl;
    return 0;
}