// 2019-02-01
#include <stdio.h>
#include <set>

using namespace std;

set<pair<int, int> > s;

int a[10005];

int main() {
    int n, x, h, m;
    scanf("%d%d%d%d", &n, &x, &h, &m);
    for (int i = 0; i < m; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        if (l > r) swap(l, r);
        if (!s.count(make_pair(l, r))) {
            s.insert(make_pair(l, r));
            --a[l + 1];
            ++a[r];
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
        printf("%d\n", a[i] + h);
    }
}
