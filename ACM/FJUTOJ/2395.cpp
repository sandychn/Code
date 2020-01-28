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

const int N = 16050;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

int n, fa[N];
LL weight[N], ans;
LL dp[N]; // dp[x] 以x为树根的子树的最大权值和
vector<int> g[N];

void dfs(int x, int fa) {
    dp[x] = weight[x];
    for (int to : g[x]) {
        if (to == fa) continue;
        dfs(to, x);
        dp[x] += max(0LL, dp[to]);
    }
    ans = max(ans, dp[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = -INFLL;
    dfs(1, -1);
    cout << ans;
    return 0;
}