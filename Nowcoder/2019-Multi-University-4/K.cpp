#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#if __cplusplus >= 201103L
#include <chrono>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 1e3 + 10;
const int K = N;
const int M = 2 * N;
const LL INFF = 0x3F3F3F3F3F3F3F3FLL;

int first[N], tot;
int n, m, start, dest;
LL dist[N][K];

struct Edge {
    int to, next, w;
} edge[M];

struct QNode {
    int pos, k;
    LL cost;
    QNode(int _pos, LL _cost, int _k) : pos(_pos), k(_k), cost(_cost) {}
    bool operator<(const QNode &b) const { return cost > b.cost; }
};

void init() {
    memset(first, -1, sizeof(first));
    tot = 0;
}

void addEdge(int u, int v, int w) {
    edge[tot].to = v, edge[tot].w = w;
    edge[tot].next = first[u];
    first[u] = tot++;
}

LL solve(int k) {
    priority_queue<QNode> q;
    memset(dist, 0x3F, sizeof(dist));
    dist[start][k] = 0;
    q.emplace(start, 0, k);
    while (!q.empty()) {
        QNode now = q.top();
        q.pop();
        now.cost = dist[now.pos][now.k];
        for (int i = first[now.pos]; ~i; i = edge[i].next) {
            int to = edge[i].to, w = edge[i].w;
            if (now.k && dist[to][now.k - 1] > now.cost) {
                dist[to][now.k - 1] = now.cost;
                q.emplace(to, now.cost, now.k - 1);
            }
            if (dist[to][now.k] > now.cost + w) {
                dist[to][now.k] = now.cost + w;
                q.emplace(to, now.cost + w, now.k);
            }
        }
    }
    LL ans = INFF;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, dist[dest][i]);
    }
    return ans;
}

int main() {
    int k;
    scanf("%d%d%d%d%d", &n, &m, &start, &dest, &k);
    init();
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    printf("%lld\n", solve(k));
    return 0;
}