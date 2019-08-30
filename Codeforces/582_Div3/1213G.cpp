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

const int N = 2e5 + 99;

int fa[N];
LL siz[N];
LL ans[N];
LL cnt;

struct Query {
    int val, id;
    bool operator<(const Query &b) const {
        return val < b.val;
    }
} que[N];

struct Edge {
    int u, v, w;
    bool operator<(const Edge &b) const {
        return w < b.w;
    }
} a[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool same(int a, int b) {
    a = find(a), b = find(b);
    return a == b;
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    cnt += siz[a] * siz[b];
    if (siz[a] > siz[b]) {
        fa[b] = a;
        siz[a] += siz[b];
    } else {
        fa[a] = b;
        siz[b] += siz[a];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a + 1, a + n);
    for (int i = 1; i <= m; ++i) {
        cin >> que[i].val;
        que[i].id = i;
    }
    sort(que + 1, que + m + 1);
    for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
    int p = 1;
    for (int i = 1; i <= m; ++i) {
        int val = que[i].val;
        for (; p < n && a[p].w <= val; ++p) {
            int u = a[p].u, v = a[p].v;
            if (same(u, v)) continue;
            join(u, v);
        }
        ans[que[i].id] = cnt;
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
