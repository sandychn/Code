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

const LL MOD = 1e9 + 7;
const int N = 1000099;

const int RED = 0, BLACK = 1;

int dp[N][2];

int dfs(int pointCount, int rootColor) {
    if (dp[pointCount][rootColor] != -1) {
        return dp[pointCount][rootColor];
    }
    int lCount = pointCount / 2, rCount = (pointCount - 1) / 2;
    if (rootColor == RED) {
        return dp[pointCount][rootColor] = (LL)dfs(lCount, BLACK) * dfs(rCount, BLACK) % MOD;
    }
    int ans = 0;
    ans = (ans + (LL)dfs(lCount, BLACK) * dfs(rCount, BLACK) % MOD) % MOD;
    ans = (ans + (LL)dfs(lCount, BLACK) * dfs(rCount, RED) % MOD) % MOD;
    ans = (ans + (LL)dfs(lCount, RED) * dfs(rCount, RED) % MOD) % MOD;
    ans = (ans + (LL)dfs(lCount, RED) * dfs(rCount, BLACK) % MOD) % MOD;
    return dp[pointCount][rootColor] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[1][RED] = 0;
    dp[1][BLACK] = 1;  // root black
    dp[2][BLACK] = 1;  // root black, leaf black
    dp[2][RED] = 1;    // root red, leaf black
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", dfs(n, BLACK));
    }
    return 0;
}