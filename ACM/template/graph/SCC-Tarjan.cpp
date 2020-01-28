/*
 * @Author: Sandy 
 * @Date: 2019-09-04 01:24:22 
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-09-04 01:25:15
 */

// Solution for HDU-1269
// Tarjan 求强连通分量

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x)                                                    \
    cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in " \
         << __FUNCTION__ << ")\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() {
        cerr << "\nTime: " << int(1000.0 * clock() / CLOCKS_PER_SEC) << " ms\n";
    }
} _tester;
#else
#define show(x)
#endif

const int N = 10050;
const int M = 100050;

struct SCC_Tarjan {
    int first[N], sccNo[N], stk[N], num[N], low[N];
    int tot, n, sccCnt, stkTop, dfn;

    struct Edge {
        int to, next;
    } edge[M];

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) first[i] = -1;
        tot = 0;
    }

    void addEdge(int u, int v) {
        edge[tot].to = v, edge[tot].next = first[u];
        first[u] = tot++;
    }

    void tarjan(int pos) {
        stk[stkTop++] = pos;
        low[pos] = num[pos] = ++dfn;
        for (int i = first[pos]; ~i; i = edge[i].next) {
            int to = edge[i].to;
            if (!num[to]) {
                tarjan(to);
                low[pos] = min(low[pos], low[to]);
            } else if (!sccNo[to]) {
                low[pos] = min(low[pos], low[to]);
            }
        }
        if (low[pos] == num[pos]) {
            ++sccCnt;
            int v;
            do {
                v = stk[--stkTop];
                sccNo[v] = sccCnt;
            } while (v != pos);
        }
    }

    void getScc() {
        sccCnt = stkTop = dfn = 0;
        for (int i = 1; i <= n; ++i) sccNo[i] = num[i] = low[i] = 0;
        for (int i = 1; i <= n; ++i) {
            if (!num[i]) tarjan(i);
        }
    }

} graph;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        graph.init(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            graph.addEdge(a, b);
        }
        graph.getScc();
        cout << (graph.sccCnt == 1 ? "Yes" : "No") << endl;
    }

    return 0;
}