#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

using namespace std;
using LL = long long;
const int INF = 1 << 30;
const int N = 1e5 + 50;

int n;

struct Node {
    LL num, Max;
} tree[N * 4];

void build(int rt, int l, int r) {
    if (l == r) {
        scanf("%lld", &tree[rt].num);
        tree[rt].Max = tree[rt].num;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].Max = max(tree[rt << 1].Max, tree[rt << 1 | 1].Max);
}

void update(int rt, int l, int r, int pos, int delta) {
    if (l == r) {
        tree[rt].num += delta;
        tree[rt].Max = tree[rt].num;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(rt << 1, l, mid, pos, delta);
    } else {
        update(rt << 1 | 1, mid + 1, r, pos, delta);
    }
    tree[rt].Max = max(tree[rt << 1].Max, tree[rt << 1 | 1].Max);
}

int ask(int rt, int l, int r, int val) {
    if (tree[rt].Max < val) return INF;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (tree[rt << 1].Max >= val) return ask(rt << 1, l, mid, val);
    return ask(rt << 1 | 1, mid + 1, r, val);
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int k;
            scanf("%d", &k);
            int ans = ask(1, 1, n, k);
            if (ans == INF) puts("no response");
            else printf("%d\n", ans);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            update(1, 1, n, x, y);
        }
    }
    return 0;
}