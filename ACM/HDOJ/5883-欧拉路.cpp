#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x)                                                     \
    cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" \
         << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() {
        cerr << "\nTime: " << int(1000.0 * clock() / CLOCKS_PER_SEC) << " ms\n";
    }
} _tester;
#else
#define show(x)
#endif

const int N = 100050;
const int M = 500050 * 2;

int deg[N];
int fa[N], size;
int n, m, weight[N];
bool vis[N];

int solve_euler_path() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = (deg[i] + 1) / 2;
        if (cnt & 1) ans ^= weight[i];
    }
    return ans;
}

int solve_euler_cycle() {
    int tmp = solve_euler_path();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if ((tmp ^ weight[i]) > ans) ans = tmp ^ weight[i];
    }
    return ans;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    fa[a] = b;
    --size;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", weight + i), fa[i] = i, deg[i] = 0;
        size = n;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            ++deg[u], ++deg[v];
            join(u, v);
        }
        if (size != 1) {
            puts("Impossible");
            continue;
        }
        int odd = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] & 1) ++odd;
        }
        if (odd == 0) {
            printf("%d\n", solve_euler_cycle());
        } else if (odd == 2) {
            printf("%d\n", solve_euler_path());
        } else {
            puts("Impossible");
        }
    }
    return 0;
}