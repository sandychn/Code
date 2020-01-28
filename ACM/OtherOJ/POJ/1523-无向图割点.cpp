#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
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

const int N = 1005;
const int M = N * N;

int first[N], tot;

struct Edge {
    int to, next;
} edge[M];

int low[N], dfn[N], sccId[N];
int ans[N];
bool cut[N];
int dfnNum, sccCnt;
int n;
int root;        // 设置dfs生成树的树根
bool hasCut;
stack<int> stk;
vector<int> dcc[N];

void init() {
    for (int i = 1; i < N; ++i) {
        dfn[i] = low[i] = 0;
        ans[i] = 0;
        first[i] = -1;
        cut[i] = false;
        dcc[i].clear();
    }
    tot = dfnNum = sccCnt = 0;
    hasCut = false;
}

void addEdge(int u, int v) {
    edge[tot].to = v, edge[tot].next = first[u];
    first[u] = tot++;
}

void tarjan(int x, int inEdge) {
    low[x] = dfn[x] = ++dfnNum;
    stk.push(x);
    if (x == root && first[root] == -1) {
        dcc[++sccCnt].push_back(x);
    }
    int flag = 0;
    for (int i = first[x]; ~i; i = edge[i].next) {
        int y = edge[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                ++flag;
                if (x != root || flag > 1) {
                    cut[x] = true;
                    ++ans[x];
                    hasCut = true;
                }
                ++sccCnt;
                int z;
                do {
                    z = stk.top();
                    stk.pop();
                    dcc[sccCnt].push_back(z);
                } while (z != y);
                dcc[sccCnt].push_back(x);
            }
        } else if (i != inEdge) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

int main() {
    int u, v;
    while (~scanf("%d", &u) && u) {
        init();
        do {
            scanf("%d", &v);
            if (u == v) continue;
            addEdge(u, v);
            addEdge(v, u);
        } while (~scanf("%d", &u) && u);

        for (int i = 1; i < N; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i, -1);
            }
        }

        static int Case;
        printf("Network #%d\n", ++Case);

        if (!hasCut) {
            puts("  No SPF nodes");
        } else {
            for (int i = 1; i < N; ++i)
                if (ans[i])
                    printf("  SPF node %d leaves %d subnets\n", i, ans[i] + 1);
        }
        puts("");
    }
    return 0;
}