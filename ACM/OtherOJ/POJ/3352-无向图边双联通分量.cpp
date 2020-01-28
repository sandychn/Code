#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

const int N = 1050;
const int M = 2050;

int first[N], tot;
int dfn[N], low[N], num;
int dccId[N], dccCnt;
bool bridge[M];
vector<int> dcc[N];
int deg[N]; // 缩点图的度

struct Edge {
    int to, next;
} edge[M];

void addEdge(int u, int v) {
    bridge[tot] = false;
    edge[tot].to = v, edge[tot].next = first[u];
    first[u] = tot++;
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        first[i] = -1;
        dfn[i] = low[i] = 0;
        dccId[i] = deg[i] = 0;
        dcc[i].clear();
    }
    dccCnt = num = tot = 0;
}

void tarjan(int x, int inEdge) {
    dfn[x] = low[x] = ++num;
    for (int i = first[x]; ~i; i = edge[i].next) {
        int y = edge[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {
                bridge[i] = bridge[i ^ 1] = true;
            }
        } else if (i != (inEdge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

void dfs(int x) {
    dccId[x] = dccCnt;
    for (int i = first[x]; ~i; i = edge[i].next) {
        int y = edge[i].to;
        if (dccId[y] || bridge[i]) continue;
        dfs(y);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }
    tarjan(1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!dccId[i]) {
            ++dccCnt;
            dfs(i);
        }
    }
    for (int i = 0; i < tot; i += 2) {
        int x = edge[i].to, y = edge[i ^ 1].to;
        if (dccId[x] == dccId[y]) continue;
        dcc[dccId[x]].push_back(dccId[y]);
        ++deg[dccId[x]];
        ++deg[dccId[y]];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            ++ans;
        }
    }
    printf("%d\n", (ans + 1) / 2);
    return 0;
}
