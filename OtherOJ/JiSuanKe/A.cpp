#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

int n, p, q, m;
unsigned SA, SB, SC;

unsigned int rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

void gen() {
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    stack<unsigned> s1;
    stack<unsigned> s2;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (rng61() % (p + q) < p) {
            unsigned val = rng61() % m + 1;
            s1.push(val);
            if (s2.empty()) s2.push(val);
            else s2.push(max(s2.top(), val));
        } else {
            if (s2.empty()) continue;
            s1.pop(), s2.pop();
        }
        if (!s2.empty()) ans ^= (1LL * i * s2.top());
    }
    static int kase;
    printf("Case #%d: %lld\n", ++kase, ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) gen();
    return 0;
}