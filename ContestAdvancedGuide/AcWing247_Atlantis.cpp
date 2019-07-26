// 2019-03-02
// 扫描线
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    static const int MAXN = 105;

    struct Line {
        double x, y1, y2;
        int sign;
        Line() {}
        Line(double x, double y1, double y2, int s): x(x), y1(y1), y2(y2), sign(s) {}
        bool operator<(const Line &b) const {
            return x < b.x;
        }
    } a[MAXN * 2];

    struct SegmentTree {
        int l, r, lc, rc;
        double len; // [l, r]区间被矩阵覆盖的长度
        int cnt; // 节点自身被覆盖的次数
    } tree[MAXN * 2 * 2];

    int tot, n;
    vector<double> v;

    int build(int l, int r) {
        int t = ++tot;
        tree[t].l = l, tree[t].r = r, tree[t].len = tree[t].cnt = 0;
        if (l != r) {
            int mid = (l + r) >> 1;
            tree[t].lc = build(l, mid);
            tree[t].rc = build(mid + 1, r);
        }
        return t;
    }

    void update(int rt, int l, int r, int v) {
        if (tree[rt].l == l && tree[rt].r == r) {
            tree[rt].cnt += v;
            if (tree[rt].cnt > 0) {
                tree[rt].len = getValue(tree[rt].r + 1) - getValue(tree[rt].l);
            } else {
                if (l == r) tree[rt].len = 0; // No child node.
                else tree[rt].len = tree[tree[rt].lc].len + tree[tree[rt].rc].len;
            }
            return;
        }
        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (l > mid) {
            update(tree[rt].rc, l, r, v);
        } else if (r <= mid) {
            update(tree[rt].lc, l, r, v);
        } else {
            update(tree[rt].lc, l, mid, v);
            update(tree[rt].rc, mid + 1, r, v);
        }
        if (tree[rt].cnt > 0) {
            tree[rt].len = getValue(tree[rt].r + 1) - getValue(tree[rt].l);
        } else {
            tree[rt].len = tree[tree[rt].lc].len + tree[tree[rt].rc].len;
        }
    }

    int getId(double x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    double getValue(int pos) {
        return v.at(pos);
    }

public:
    bool atlantis() {
        if (scanf("%d", &n) == EOF || !n) return false;
        v.clear();
        double x1, x2, y1, y2;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            v.push_back(y1), v.push_back(y2);
            a[i * 2] = Line(x1, y1, y2, 1), a[i * 2 + 1] = Line(x2, y1, y2, -1);
        }
        sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
        sort(a, a + n * 2);
        int siz = v.size();

        tot = 0;
        build(0, siz - 1);
        double ans = 0;

        for (int i = 0; i < n << 1; ++i) {
            int p = getId(a[i].y1), q = getId(a[i].y2);
            update(1, p, q - 1, a[i].sign);
            ans += (a[i + 1].x - a[i].x) * tree[1].len;
        }

        static int caseCnt = 0;
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++caseCnt, ans);
        return true;
    }
} sol;

int main() {
    while (sol.atlantis());
    return 0;
}
