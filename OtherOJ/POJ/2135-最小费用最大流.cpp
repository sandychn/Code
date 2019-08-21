/*
 * @Author: Sandy 
 * @Date: 2019-08-22 00:52:03 
 * @Last Modified by:   Sandy 
 * @Last Modified time: 2019-08-22 00:52:03 
 */

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

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

const int INF = 0x3F3F3F3F;
const int N = 1050;
const int M = 10050 * 2;

int n, first[N];

struct MinCostMaxFlow {
    struct Edge {
        int to, cost, cap, next;
    } edge[M * 2];
    int first[N], tot, n;
    int dist[N], pre[N], flow[N];
    bool inq[N];
    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(*first) * (n + 1));
    }
    void _addEdge(int u, int v, int cost, int cap) {
        edge[tot].to = v, edge[tot].cost = cost, edge[tot].cap = cap;
        edge[tot].next = first[u], first[u] = tot++;
    }
    void addFlowEdge(int u, int v, int cost, int cap) {
        _addEdge(u, v, cost, cap), _addEdge(v, u, -cost, 0);
    }
    bool spfa(int s, int t) {
        for (int i = 0; i <= n; ++i) {
            pre[i] = -1, inq[i] = false;
            dist[i] = flow[i] = INF;
        }
        queue<int> q;
        q.push(s);
        dist[s] = 0, inq[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int i = first[u]; ~i; i = edge[i].next) {
                if (edge[i].cap) {
                    int v = edge[i].to, cost = edge[i].cost;
                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        flow[v] = min(edge[i].cap, flow[u]);
                        pre[v] = i; // 来边编号
                        if (!inq[v]) inq[v] = true, q.push(v);
                    }
                }
            }
        }
        return dist[t] != INF; // s->t的最短路(最小费用)
    }
    int minCostMaxFlow(int s, int t) {
        int cost = 0;
        while (spfa(s, t)) {
            int pos = t, id;
            while (pre[pos] != -1) {
                edge[id = pre[pos]].cap -= flow[t];
                edge[id ^ 1].cap += flow[t];
                pos = edge[id ^ 1].to;
            }
            cost += dist[t] * flow[t];
        }
        return cost;
    }
} MCMF;

int main() {
    int m;
    scanf("%d%d", &n, &m);
    MCMF.init(n + 2);
    for (int i = 1, u, v, w; m--; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        MCMF.addFlowEdge(u, v, w, 1);
        MCMF.addFlowEdge(v, u, w, 1);
    }
    int s = n + 1, t = n + 2;
    MCMF.addFlowEdge(s, 1, 0, 2);
    MCMF.addFlowEdge(n, t, 0, 2);
    printf("%d\n", MCMF.minCostMaxFlow(s, t));
    return 0;
}