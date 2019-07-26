// 2019-02-10
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL a[1000005];

int main() {
    int n; scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        sum += a[i];
    }
    if (sum % n) return 1;
    LL avg = sum / n;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + a[i] - avg;
    }
    nth_element(a + 1, a + (n + 1) / 2, a + n + 1);
    LL mid = a[(n + 1) / 2];
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += llabs(mid - a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
