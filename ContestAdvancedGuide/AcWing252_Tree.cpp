// 2019-03-03
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
const int MAXM = MAXN * 2;

int n, k;
int result; // 最终结果
int centerMaxPart; // 重心对应的maxPart
int center; // 重心位置
int dist[MAXN]; // dist[x]表示点x到根节点p的距离
int belong[MAXN]; // belong[x]表示点x属于根节点p的哪一颗子树, belong[p]=p
int a[MAXN]; // 树中节点按照d值排序
int siz[MAXN]; // 树所含节点个数
int cnt[MAXN]; // cnt[s]维护在l+1到r之间满足b[a[i]]=s的位置i的个数
int id; // a中节点数
// bool v[MAXN];
bool w[MAXN]; // 是否被删除

int first[MAXN], tot;

template<class T>
inline void memorySet(T *a, int val, int n) {
    memset(a, val, sizeof(*a) * n);
}

struct Edge {
    int to, w, next;
    void setVal(int tt, int ww, int nex) {
        to = tt, w = ww, next = nex;
    }
} e[MAXM];

inline void addEdge(int x, int y, int z) {
    e[++tot].setVal(y, z, first[x]), first[x] = tot;
}

void dfsGetCenter(int ss, int rt, int pre) {
    // v[rt] = true;
    siz[rt] = 1;
    int maxPart = 0;
    for (int i = first[rt]; ~i; i = e[i].next) {
        int y = e[i].to;
        if (y == pre || w[y]) continue;
        dfsGetCenter(ss, y, rt);
        siz[rt] += siz[y];
        maxPart = max(maxPart, siz[y]);
    }
    maxPart = max(maxPart, ss - siz[rt]);
    if (maxPart < centerMaxPart) centerMaxPart = maxPart, center = rt;
}

void dfs(int rt, int pre) {
    // v[rt] = true;
    for (int i = first[rt]; ~i; i = e[i].next) {
        int y = e[i].to, val = e[i].w;
        if (y == pre || w[y]) continue;
        a[++id] = y;
        belong[y] = belong[rt];
        ++cnt[belong[y]];
        dist[y] = dist[rt] + val;
        dfs(y, rt);
    }
}

inline bool cmp(const int i, const int j) {
    return dist[i] < dist[j];
}

void solve(int ss, int x) {
    centerMaxPart = ss;
    // memorySet(v, 0, n);
    dfsGetCenter(ss, x, x);
    memorySet(dist, 0, n);
    memorySet(cnt, 0, n);
    // memorySet(v, 0, n);
    id = 0;
    a[++id] = belong[center] = center;
    w[center] = true; // 删除该点
    ++cnt[center];
    for (int i = first[center]; ~i; i = e[i].next) {
        int y = e[i].to, z = e[i].w;
        if (y == center || w[y]) continue;
        a[++id] = belong[y] = y;
        ++cnt[y];
        dist[y] = z;
        dfs(y, center);
    }
    sort(a + 1, a + id + 1, cmp);
    int l = 1, r = id;
    --cnt[belong[a[1]]];
    while (l < r) {
        while (dist[a[l]] + dist[a[r]] > k) {
            --cnt[belong[a[r]]];
            --r;
        }
        result += r - l - cnt[belong[a[l]]];
        --cnt[belong[a[++l]]];
    }
    int now = center;
    for (int i = first[now]; ~i; i = e[i].next) {
        int y = e[i].to;
        if (w[y]) continue;
        solve(siz[y], y);
    }
}

void tree() {
    tot = -1;
    memorySet(first, -1, n);
    for (int i = 1, x, y, z; i < n; ++i)
        scanf("%d%d%d", &x, &y, &z), addEdge(x, y, z), addEdge(y, x, z);
    memorySet(w, 0, n);
    result = 0;
    solve(n, 0);
    printf("%d\n", result);
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF && (n || k)) tree();
    return 0;
}
