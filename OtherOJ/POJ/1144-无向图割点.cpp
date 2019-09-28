#include <algorithm>
#include <cassert>
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

const int N = 105;
const int M = 100005;

char buf[M];
vector<int> edge[N];
int low[N], num[N];
bool isCut[N];
int dfn, n;
int root;  // 设置dfs生成树的树根

void init() {
    for (int i = 1; i <= n; ++i) {
        low[i] = num[i] = 0;
        isCut[i] = false;
    }
    dfn = 0;
}

void tarjan(int u, int fa) {
    low[u] = num[u] = ++dfn;
    int child = 0;
    for (int i = 0; i < (int)edge[u].size(); ++i) {
        int v = edge[u][i];
        if (!num[v]) {
            ++child;
            tarjan(v, u);
            low[u] = min(low[v], low[u]);
            if (low[v] >= num[u] && u != root) {
                isCut[u] = true;
            }
        } else if (num[v] < num[u] && v != fa) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (u == root && child >= 2) isCut[root] = true;
}

int main() {
    while (scanf("%d%*c", &n) != EOF && n) {
        for (int i = 1; i <= n; ++i) edge[i].clear();
        while (true) {
            gets(buf);
            int u, v;
            sscanf(buf, "%d", &u);
            if (u == 0) break;
            char *p = strtok(buf, " ");
            while ((p = strtok(NULL, " "))) {
                sscanf(p, "%d", &v);
                edge[u].push_back(v);
                edge[v].push_back(u);
            }
        }
        root = 1;
        init();
        tarjan(root, 0);
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += isCut[i];
        printf("%d\n", ans);
    }
    return 0;
}