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

const int N = 1e5 + 10;
const int K = N;
const int M = 2 * N;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

int ans;
int first[N], tot;
int siz[N], d[N];
bool people[K], vis[N], ignored[N];
bool v[N];
vector<int> g[N];

struct Edge {
    int to, next, w;
} edge[M];

void init() {
    memset(first, -1, sizeof(first));
    tot = 0;
}

void addEdge(int u, int v) {
    edge[tot].to = v, edge[tot].next = first[u];
    first[u] = tot++;
}

int dfs(int x) {
    vis[x] = 1;
    int size = people[x];
    for (int i = first[x]; ~i; i = edge[i].next) {
        int to = edge[i].to;
        if (!vis[to]) {
            size += dfs(to);
        }
    }
    return siz[x] = size;
}

void dp(int x) {
    v[x] = 1;
    for (int y : g[x]) {
        if (v[y]) continue;
        dp(y);
        ans = max(ans, d[x] + d[y] + 1);
        d[x] = max(d[x], d[y] + 1);
    }
}

int main() {
#ifdef _LOCAL
    freopen("test.in", "r", stdin);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    int source = 0;
    for (int i = 1, x; i <= k; ++i) {
        scanf("%d", &x);
        if (!source) source = x;
        people[x] = 1;
    }
    dfs(source);
    for (int i = 1; i <= n; ++i) {
        if (siz[i] == 0) {
            ignored[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ignored[i]) continue;
        for (int j = first[i]; ~j; j = edge[j].next) {
            int to = edge[j].to;
            if (ignored[to]) continue;
            g[i].push_back(to);
        }
    }
    dp(source);
    printf("%d\n", (ans + 1) / 2);
    return 0;
}
