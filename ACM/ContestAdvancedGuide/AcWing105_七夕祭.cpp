// 2019-02-04
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
using LL = long long;

LL row[100005], col[100005], sum[100005];

LL solve(int total, int n, LL *a) {
    if (total % n != 0) return -1;
    int t = total / n;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i] - t;
    }
    nth_element(sum + 1, sum + (n + 1) / 2, sum + n + 1);
    LL mid = sum[(n + 1) / 2], ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(sum[i] - mid);
    }
    return ans;
}

int main() {
    int n, m, t, x, y; scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &x, &y);
        ++row[x], ++col[y];
    }
    LL r = solve(t, n, row), c = solve(t, m, col);
    if (r != -1 && c != -1) {
        printf("both %lld\n", r + c);
    } else if (r != -1) {
        printf("row %lld\n", r);
    } else if (c != -1) {
        printf("column %lld\n", c);
    } else {
        puts("impossible");
    }
    return 0;
}
