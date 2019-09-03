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

struct Graph {
    int first[N], tot, n;

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
};

struct Kosaraju {
    Graph g, rg;
    int sccNo[N], order[N];
    bool vis[N];
    int n, sccCnt, orderId;

    void init(int n) {
        this->n = n;
        g.init(n), rg.init(n);
    }

    void addEdge(int u, int v) {
        g.addEdge(u, v), rg.addEdge(v, u);
    }

    void dfs1(int pos) {
        vis[pos] = true;
        for (int i = g.first[pos]; ~i; i = g.edge[i].next) {
            int to = g.edge[i].to;
            if (!vis[to]) dfs1(to);
        }
        order[++orderId] = pos;
    }

    void dfs2(int pos) {
        sccNo[pos] = sccCnt;
        for (int i = rg.first[pos]; ~i; i = rg.edge[i].next) {
            int to = rg.edge[i].to;
            if (!sccNo[to]) dfs2(to);
        }
    }

    void getScc() {
        for (int i = 1; i <= n; ++i) sccNo[i] = 0, vis[i] = false;
        orderId = sccCnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) dfs1(i);
        }
        for (int i = n; i >= 1; --i) {
            int u = order[i];
            if (!sccNo[u]) ++sccCnt, dfs2(u);
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