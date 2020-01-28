#include <bits/stdc++.h>

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

const int N = 1e5 + 10;
const int M = 20;

char s[N];
int sa[N], rk[N], cnt[N], height[N], t1[N], t2[N];
int Log2[N], f[N][M];

struct SegmentTrees {
    struct Node {
        int lson, rson, data;
    } t[40 * N];
    int tot, root[N];
    inline void push_up(int p) {
        t[p].data = t[t[p].lson].data + t[t[p].rson].data;
    }
    inline void init() {
        tot = 0;
    }
    int build(int l, int r) {
        int p = ++tot;
        if(l == r) {
            t[p].data = 0;
            return p;
        }
        int mid = (l + r) >> 1;
        t[p].lson = build(l, mid);
        t[p].rson = build(mid + 1, r);
        push_up(p);
        return p;
    }
    int insert(int now, int l, int r, int x, int val) {
        int p = ++tot;
        t[p] = t[now];
        if(l == r) {
            t[p].data += val;
            return p;
        }
        int mid = (l + r) >> 1;
        if(x <= mid) {
            t[p].lson = insert(t[now].lson, l, mid, x, val);
        } else {
            t[p].rson = insert(t[now].rson, mid + 1, r, x, val);
        }
        push_up(p);
        return p;
    }
} tree;

int ask(int p, int q, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int lcnt = tree.t[tree.t[p].lson].data - tree.t[tree.t[q].lson].data;
    if(k <= lcnt) return ask(tree.t[p].lson, tree.t[q].lson, l, mid, k);
    return ask(tree.t[p].rson, tree.t[q].rson, mid + 1, r, k - lcnt);
}

void calcSA(char *s, int n) {
    int m = 256;
    int i, *x = t1, *y = t2;
    for (i = 1; i <= m; ++i) cnt[i] = 0;
    for (i = 1; i <= n; ++i) ++cnt[x[i] = s[i]];
    for (i = 2; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k + 1; i <= n; ++i) y[++p] = i;
        for (i = 1; i <= n; ++i)
            if (sa[i] > k) y[++p] = sa[i] - k;
        for (i = 1; i <= m; ++i) cnt[i] = 0;
        for (i = 1; i <= n; ++i) ++cnt[x[i]];
        for (i = 2; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[x[y[i]]]--] = y[i];
        swap(x, y);
        x[sa[1]] = 1;
        p = 1;
        for (i = 2; i <= n; ++i)
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]) ? p : ++p;
        if (p >= n) break;
        m = p;
    }
    for (i = 1; i <= n; ++i) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 1) {
            height[rk[i]] = 0;
        } else {
            if (k) --k;
            int j = sa[rk[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
            height[rk[i]] = k;
        }
    }
}

void initLog2() {
    for (int i = 0; (1 << i) < N; ++i)
        Log2[1 << i] = i;
    for (int i = 1; i < N; ++i) {
        if (!Log2[i]) Log2[i] = Log2[i - 1];
    }
}

void stInit(int n) {
    for (int i = 1; i <= n; ++i)
        f[i][0] = height[i];
    int t = Log2[n] + 1;
    for (int j = 1; j < t; ++j) {
        for (int i = 1; i <= n - (1 << j) + 1; ++i) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int stQuery(int l, int r) {
    if (l > r) return 0;
    int k = Log2[r - l + 1];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    initLog2();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d%s", &n, &q, s + 1);
        calcSA(s, n);
        stInit(n);
        tree.init();
        tree.root[0] = tree.build(1, n);
        for (int i = 1; i <= n; ++i)
            tree.root[i] = tree.insert(tree.root[i - 1], 1, n, sa[i], 1);
        while (q--) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            int len = r - l + 1;
            int ll = rk[l], rr = rk[l];
            int left = rk[l] + 1, right = n;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (stQuery(left, mid) >= len) {
                    rr = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            left = 2, right = rk[l];
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (stQuery(mid, right) >= len) {
                    ll = mid - 1;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (rr - ll + 1 < k) {
                puts("-1");
            } else {
                printf("%d\n", ask(tree.root[rr], tree.root[ll - 1], 1, n, k));
            }
        }
    }
    return 0;
}