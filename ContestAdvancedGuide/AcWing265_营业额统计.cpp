// 2019-03-06
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

class Treap {
private:
    static const int INF = 0x3F3F3F3F;
    static const int INTMAX = 0x7FFFFFFF;
    static const int MAX = 33000;

    struct Node {
        int l, r, val, dat, cnt, siz;
    } a[MAX];
    int tot, root;

    int create(int val) {
        Node &p = a[++tot];
        p.l = p.r = 0, p.val = val, p.dat = rand(), p.cnt = p.siz = 1;
        return tot;
    }

    void update(int p) {
        a[p].siz = a[a[p].l].siz + a[a[p].r].siz + a[p].cnt;
    }

    void zig(int &p) {
        int q = a[p].l;
        a[p].l = a[q].r, a[q].r = p, p = q, update(a[p].r), update(p);
    }

    void zag(int &p) {
        int q = a[p].r;
        a[p].r = a[q].l, a[q].l = p, p = q, update(a[p].l), update(p);
    }

    int in_getRankByVal(int p, int val) {
        if (!p) return 0;
        if (val == a[p].val) return a[a[p].l].siz + 1;
        if (val < a[p].val) return in_getRankByVal(a[p].l, val);
        return a[a[p].l].siz + a[p].cnt + in_getRankByVal(a[p].r, val);
    }

    int in_getValByRank(int p, int rk) {
        if (!p) return INF;
        if (a[a[p].l].siz >= rk) return in_getValByRank(a[p].l, rk);
        if (a[a[p].l].siz + a[p].cnt >= rk) return a[p].val;
        return in_getValByRank(a[p].r, rk - a[a[p].l].siz - a[p].cnt);
    }

    void in_insert(int &p, int val) {
        if (!p) {
            p = create(val);
            return;
        }
        if (val == a[p].val) {
            ++a[p].cnt;
        } else if (val < a[p].val) {
            in_insert(a[p].l, val);
            if (a[p].dat < a[a[p].l].dat) zig(p);
        } else {
            in_insert(a[p].r, val);
            if (a[p].dat < a[a[p].r].dat) zag(p);
        }
        update(p);
    }

    void in_remove(int &p, int val) {
        if (!p) return;
        if (val == a[p].val) {
            if (a[p].cnt > 1) {
                --a[p].cnt, update(p);
                return;
            }
            // a[p].cnt == 1. Deleting node p.
            if (a[p].l || a[p].r) { // 还不是叶子 向下旋转
                if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat) {
                    zig(p), in_remove(a[p].r, val);
                } else {
                    zag(p), in_remove(a[p].l, val);
                }
                update(p);
            } else p = 0; // Is a leaf. It can be deleted directly.
            return;
        }
        // val != a[p].val
        in_remove(val < a[p].val ? a[p].l : a[p].r, val), update(p);
    }

public:

    void init() {
        tot = 0;
        create(-INF), create(INF);
        // If getPre()'s parameter 'val' <= the minimum value in the tree, -INF is returned.
        // If getNext()'s parameter 'val' >= the maximum value in the tree, INF is returned.
        // That's why there should be two nodes INF and -INF.
        a[root = 1].r = 2;
        a[0].dat = -INTMAX; // if rand() returns a negative number, this will avoid node #0 from zig/zag up.
    }

    int getRankByVal(int val) {
        return in_getRankByVal(root, val);
    }

    int getValByRank(int rk) {
        return in_getValByRank(root, rk);
    }

    void insert(int val) {
        in_insert(root, val);
    }

    void remove(int val) {
        in_remove(root, val);
    }

    int count(int val) {
        int p = root;
        while (p) {
            if (val == a[p].val) break;
            if (val < a[p].val) p = a[p].l;
            else p = a[p].r;
        }
        return a[p].cnt;
    }

    int getPre(int val) {
        int ans = 1, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].l) {
                    p = a[p].l;
                    while (a[p].r) p = a[p].r;
                    ans = p;
                }
                break;
            }
            if (a[p].val < val && a[p].val > a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }

    int getNext(int val) {
        int ans = 2, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].r) {
                    p = a[p].r;
                    while (a[p].l) p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val && a[p].val < a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }

} tree;

int main() {
    srand(time(NULL));
    tree.init();
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    int ans = x;
    tree.insert(x);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        if (!tree.count(x)) {
            ans += min(abs(tree.getPre(x) - x), abs(tree.getNext(x) - x));
            tree.insert(x);
        }
    }
    printf("%d\n", ans);
    return 0;
}
