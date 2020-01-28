// 2019-03-02
// 扩展域并查集/边带权并查集两种解法
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 { // 扩展域并查集
private:
    static const int MAXM = 10010;
    struct Node {
        int l, r, odd;
    } a[MAXM];
    int fa[MAXM * 4];
    int n, m;
    vector<int> v;

    int getId(int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            fa[i] = i;
        }
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        fa[find(x)] = find(y);
    }

    void read_compress() {
        char str[10];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%s", &a[i].l, &a[i].r, str);
            --a[i].l;
            a[i].odd = (*str == 'o' ? 1 : 0);
            v.push_back(a[i].l);
            v.push_back(a[i].r);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

public:
    void solve() {
        scanf("%d%d", &n, &m);
        read_compress();
        init(40000);
        for (int i = 0; i < m; ++i) {
            int x = getId(a[i].l), y = getId(a[i].r);
            if (a[i].odd) {
                if (same(x, y) || same(x + 20000, y + 20000)) {
                    printf("%d\n", i);
                    return;
                }
                merge(x, y + 20000);
                merge(x + 20000, y);
            } else {
                if (same(x, y + 20000) || same(x + 20000, y)) {
                    printf("%d\n", i);
                    return;
                }
                merge(x, y);
                merge(x + 20000, y + 20000);
            }
        }
        printf("%d\n", m);
    }
} sol;

class Solution2 { // 边带权并查集
private:
    static const int MAXM = 10010;
    struct Node {
        int l, r, different;
    } a[MAXM];
    int fa[MAXM * 2], d[MAXM * 2];
    int n, m;
    vector<int> v;

    int getId(int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            fa[i] = i;
            d[i] = 0;
        }
    }

    int find(int x) {
        if (x == fa[x]) return x;
        int rt = find(fa[x]);
        d[x] = d[x] ^ d[fa[x]];
        return fa[x] = rt;
    }

    void read_compress() {
        char str[10];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%s", &a[i].l, &a[i].r, str);
            --a[i].l;
            a[i].different = (*str == 'o' ? 1 : 0);
            v.push_back(a[i].l);
            v.push_back(a[i].r);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

public:
    void solve() {
        scanf("%d%d", &n, &m);
        read_compress();
        init(2 * int(v.size()));
        for (int i = 0; i < m; ++i) {
            int x = getId(a[i].l), y = getId(a[i].r);
            int p = find(x), q = find(y);
            if (p == q) {
                if ((d[x] ^ d[y]) != a[i].different) {
                    printf("%d\n", i);
                    return;
                }
            } else {
                fa[p] = q;
                d[p] = d[x] ^ d[y] ^ a[i].different;
            }
        }
        printf("%d\n", m);
    }
};

int main() {
    sol.solve();
    return 0;
}
