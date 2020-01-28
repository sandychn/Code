// 2019-02-01
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long LL;
const int MOD = 9901;

vector<pair<LL, LL> > divisor;
// prime divisors. first: number, second: time;

LL quick_mul(LL a, LL n, LL p) {
    LL ans = 0;
    while (n) {
        if (n & 1) {
            ans = (ans + a) % p;
        }
        a = (a << 1) % p;
        n >>= 1;
    }
    return ans;
}

LL quick_pow(LL a, LL n, LL p) {
    LL ans = 1;
    while (n) {
        if (n & 1) {
            ans = quick_mul(ans, a, p);
        }
        a = quick_mul(a, a, p);
        n >>= 1;
    }
    return ans;
}

// 1 + a^1 + a^2 + a^3 + ... + a^b
LL sum(LL a, LL b) {
    if (b == 0) {
        return 1;
    }
    if (b & 1) {
        return (((1 + quick_pow(a, (b + 1) / 2, MOD)) % MOD) * sum(a, (b - 1) / 2)) % MOD;
    }
    return ((((1 + quick_pow(a, b / 2, MOD)) % MOD) * sum(a, b / 2 - 1)) % MOD + quick_pow(a, b, MOD)) % MOD;
}

int main() {
    LL a, b;
    scanf("%lld%lld", &a, &b);
    if (!a) return puts("0"), 0;
    LL temp = a;
    for (LL i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            LL cnt = 0;
            while (temp % i == 0) {
                ++cnt;
                temp /= i;
            }
            divisor.push_back(make_pair(i, cnt));
        }
    }
    if (temp != 1) divisor.push_back(make_pair(temp, 1));
    LL ans = 1;
    for (int i = 0; i < (int) divisor.size(); ++i) {
        ans *= sum(divisor[i].first, b * divisor[i].second);
        ans %= MOD;
    }
    printf("%lld\n", ans);
    /*
    LL ans = 1;
    for (int i = 0; i < (int) divisor.size(); ++i) {
        LL n = b * divisor[i].second + 1;
        LL y = divisor[i].first - 1;
        LL x = (quick_pow(divisor[i].first, n, y * MOD) - 1 + y * MOD) % (y * MOD);
        ans *= x / y;
        ans %= MOD;
    }
    printf("%lld\n", ans);
    */
    return 0;
}
