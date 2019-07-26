// 2019-02-06
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;
const int MAXN = 5e5 + 7;
LL a[MAXN], b[MAXN], c[MAXN];

void Merge(LL *a1, LL *a2, LL *dest, int l1, int r1, int l2, int r2) {
    while (l1 <= r1 && l2 <= r2) {
        if (a1[l1] <= a2[l2])
            *dest++ = a1[l1++];
        else
            *dest++ = a2[l2++];
    }
    while (l1 <= r1)
        *dest++ = a1[l1++];
    while (l2 <= r2)
        *dest++ = a2[l2++];
}

bool check(int l, int r, int m, LL t) {
    LL sum = 0;
    for (int i = l, j = r; i < j && m; ++i, --j, --m) {
        sum += (c[i] - c[j]) * (c[i] - c[j]);
        if (sum > t) return false;
    }
    return true;
}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int n, m;
        LL t;
        scanf("%d%d%lld", &n, &m, &t);
        for (int i = 0; i < n; ++i)
            scanf("%lld", a + i);
        int ans = 0, l = 0;
        while (l < n) {
            int len = 1, r = l;
            b[l] = a[l];
            while (len) {
                if (r + len >= n) {
                    len >>= 1;
                    continue;
                }
                for (int i = r + 1; i <= r + len; ++i) {
                    b[i] = a[i];
                }
                sort(b + r + 1, b + r + len + 1);
                Merge(a, b, c + l, l, r, r + 1, r + len);
                if (check(l, r + len, m, t)) {
                    memcpy(a + l, c + l, sizeof(LL) * (r + len - l + 1));
                    r += len, len <<= 1;
                }
                else {
                    len >>= 1;
                }
            }
            l = r + 1;
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
