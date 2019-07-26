// 2019-01-31
#include <stdio.h>

using LL = long long;

LL quick_add(LL a, LL b, LL p) {
    LL ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    LL a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld\n", quick_add(a, b, p));
}
