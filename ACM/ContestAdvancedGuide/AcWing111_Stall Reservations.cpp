// 2019-02-07
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long LL;

struct Cow {
    int l, r, id;
    bool operator<(const Cow &b) const {
        return r > b.r;
    }
} a[50005];

bool cmp(const Cow &a, const Cow &b) {
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}

priority_queue<Cow> heap;
int ans[50005];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i;
    }
    sort(a, a + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (heap.empty() || heap.top().r >= a[i].l) {
            ans[a[i].id] = ++cnt;
        } else {
            ans[a[i].id] = ans[heap.top().id];
            heap.pop();
        }
        heap.push(a[i]);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
