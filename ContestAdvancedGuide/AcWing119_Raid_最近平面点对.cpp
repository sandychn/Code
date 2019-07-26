// 2019-02-10
// 平面最近点对

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
typedef long long LL;

const LL INF = 0x7FFFFFFFFFFFFFFFLL;

inline LL square(LL x) {
    return x * x;
}

struct Point {
    LL x, y;
    int w;
    bool operator<(const Point &b) const {
        return x < b.x;
    }
} a[200007], b[200007];

inline LL dist(const Point &a, const Point &b) {
    if (a.w == b.w) return INF;
    return square(a.x - b.x) + square(a.y - b.y);
}

void Merge(int l, int mid, int r) {
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || (i <= mid && a[i].y < a[j].y)) {
            b[k] = a[i++];
        } else {
            b[k] = a[j++];
        }
    }
    for (int k = l; k <= r; ++k) a[k] = b[k];
}

void solve(int l, int r, LL &ans) {
    if (l == r) return;
    int mid = (l + r) >> 1, k = 0;
    LL midx = a[mid].x;
    solve(l, mid, ans), solve(mid + 1, r, ans), Merge(l, mid, r);
    for (int i = l; i <= r; ++i) {
        if (square(llabs(a[i].x - midx)) <= ans)
            b[++k] = a[i];
    }
    for (int i = 1; i < k; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            if (square(b[j].y - b[i].y) < ans) {
                ans = min(ans, dist(b[i], b[j]));
            } else {
                break;
            }
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].y);
            a[i].w = 1;
        }
        for (int i = n; i < (n << 1); ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].y);
            a[i].w = 2;
        }
        sort(a, a + 2 * n);
        LL ans = INF;
        solve(0, 2 * n - 1, ans);
        printf("%.3f\n", sqrt(ans));
    }
    return 0;
}
