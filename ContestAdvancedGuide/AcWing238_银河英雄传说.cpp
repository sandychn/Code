// 2019-02-26
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
private:
    static const int MAXN = 30010;
    static const int N = 30000;
    int fa[MAXN], depth[MAXN], siz[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            depth[i] = 0;
            siz[i] = 1;
        }
    }

    int find(int x) {
        if (fa[x] == x) return x;
        int rt = find(fa[x]);
        depth[x] += depth[fa[x]];
        return fa[x] = rt;
    }

    void join(int x, int y) { // x after y
        x = find(x), y = find(y);
        if (x == y) return;
        fa[x] = y;
        depth[x] = siz[y];
        siz[y] += siz[x];
    }

    int get(int x) {
        find(x);
        return depth[x];
    }

public:
    void solve() {
        int T;
        scanf("%d", &T);
        init(30000);
        for (int i = 0; i < T; ++i) {
            char op[5];
            int x, y;
            scanf("%s%d%d", op, &x, &y);
            if (*op == 'M') {
                join(x, y);
            } else {
                if (find(x) == find(y)) {
                    printf("%d\n", max(abs(get(y) - get(x)) - 1, 0));
                } else {
                    puts("-1");
                }
            }
        }
    }
} sol;

int main() {
    sol.solve();
    return 0;
}
