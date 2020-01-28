// 2019-04-26
#include <stdio.h>
#include <algorithm>

using namespace std;
const int N = 45000; // sqrt(2e9)
const int M = 45000;

int prime[M + 5], cnt;
bool v[N + 5];
int a, b, c, d;

void primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (v[i]) continue;
        prime[++cnt] = i;
        for (int j = i; j <= n / i; ++j) v[i * j] = true;
    }
}

int calc(int a, int p) {
    int ret = 0;
    while (a % p == 0) {
        ++ret;
        a /= p;
    }
    return ret;
}

int getCount(int p) {
    int ma = calc(a, p), mb = calc(b, p), mc = calc(c, p), md = calc(d, p);
    if (ma > mc && mb < md && mc == md) return 1; // mx = mc = md
    if (ma > mc && mb == md && mc <= md) return 1; // mx = mc
    if (ma == mc && mb < md && mc <= md) return 1; // mx = md
    if (ma == mc && mb == md && mc <= md) return md - mc + 1; // mc <= mx <= md
    return 0;
}

int main() {
    primes(N);
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%d", &a, &c, &b, &d);
        int ans = 1;
        for (int i = 1; i <= cnt && prime[i] <= d && a; ++i) {
            if (d % prime[i] == 0) {
                ans *= getCount(prime[i]);
                while (d % prime[i] == 0) d /= prime[i];
            }
        }
        // d is a large prime number.
        if (d != 1) ans *= getCount(d);
        printf("%d\n", ans);
    }
   return 0;
}
