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

const int N = 1050;
const int M = 1050;

int v[N], sum[N];
int dp[N][M];
pair<int, int> a[M];

void solve(int n, int m, int k) {
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + v[i];
    int j = 1, Max = 0;
    for (int i = 1; i <= n; ++i) {
        while (j <= m) {
            if (a[j].first == i) {
                Max = max(Max, a[j].second);
                ++j;
            } else {
                break;
            }
        }
        for (int l = 0; l < k; ++l) {
            dp[i][l] = max(dp[i][l], dp[i - 1][l]);
            if (Max) {
                dp[Max][l + 1] = max(dp[Max][l + 1], dp[i - 1][l] + sum[Max] - sum[i - 1]);
            }
        }
        dp[i][k] = max(dp[i][k], dp[i - 1][k]);
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for (int i = 1; i <= m; ++i) scanf("%d%d", &a[i].first, &a[i].second);
    solve(n, m, k);
    printf("%d\n", dp[n][k]);
    return 0;
}