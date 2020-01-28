// 2019-04-18
#include <stdio.h>

const int N = 1e6 + 10;

int num[N], ex[N];
bool v[N];
int prime[N], tot;

void primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (v[i]) continue;
        prime[++tot] = i;
        for (int j = i; j <= n / i; ++j) {
            v[i * j] = true;
        }
    }
}

int main() {
    primes(N + 3);
    int n;
    scanf("%d", &n);
    for (int i = 1; prime[i] <= n; ++i) {
        int x = prime[i];
        num[i] = x;
        for (long long j = x; j <= n; j *= x) {
            ex[i] += n / j;
        }
    }
    for (int i = 1; num[i]; ++i) {
        printf("%d %d\n", num[i], ex[i]);
    }
    return 0;
}