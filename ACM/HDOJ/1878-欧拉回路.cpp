#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

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

int deg[N];
vector<int> edge[N];
bool vis[N]; // DFS检查联通
int fa[N]; // 或用并查集检查联通

void dfs(int x) {
    vis[x] = true;
    for (int to : edge[x]) {
        if (!vis[to]) dfs(to);
    }
}

bool isConnected(int n) {
    for (int i = 1; i <= n; ++i) vis[i] = false;
    dfs(1);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) return false;
    return true;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool isConnected_DSU(int n) {
    int size = n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int to : edge[i]) {
            int x = find(i), y = find(to);
            if (x != y) {
                --size;
                fa[x] = y;
            }
        }
    }
    return size == 1;
}

int main() {
    int n, m;
    while (~scanf("%d", &n) && n) {
        scanf("%d", &m);
        int u, v;
        for (int i = 1; i <= n; ++i) {
            deg[i] = 0;
            edge[i].clear();
        }
        while (m--) {
            scanf("%d%d", &u, &v), ++deg[u], ++deg[v];
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int odd = 0, even = 0;
        for (int i = 1; i <= n; ++i) {
            (deg[i] & 1) ? ++odd : ++even;
        }
        if (even == n && isConnected_DSU(n)) { // 欧拉回路
            puts("1");
        } else {
            puts("0");
        }
    }
    return 0;
}