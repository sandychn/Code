// 2019-02-09
#include <stdio.h>

struct Node {
    int father, time, val;
    double w;
} a[1005];

int findPos(int n, int r) {
    int pos;
    double wMax = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].w > wMax && i != r) {
            wMax = a[i].w;
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, r;
    while (scanf("%d%d", &n, &r) != EOF && (n || r)) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].val);
            a[i].w = a[i].val;
            a[i].time = 1;
            ans += a[i].val;
        }
        for (int i = 1, u, v; i < n; ++i) {
            scanf("%d%d", &u, &v);
            a[v].father = u;
        }
        for (int i = 1; i < n; ++i) {
            int pos = findPos(n, r);
            a[pos].w = 0;
            int fa = a[pos].father;
            ans += a[pos].val * a[fa].time;
            // a[fa].time 表示 点集 中点个数
            // 多向上一层所付出的代价
            for (int j = 1; j <= n; ++j) {
                if (a[j].father == pos) {
                    a[j].father = fa;
                }
            }
            a[fa].time += a[pos].time;
            a[fa].val += a[pos].val;
            a[fa].w = double(a[fa].val) / a[fa].time;
        }
        printf("%d\n", ans);
    }
    return 0;
}
