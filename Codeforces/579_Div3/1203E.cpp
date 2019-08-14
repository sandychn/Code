#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
 
#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif
 
const int INF = 0x3F3F3F3F;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;
 
const int N = 150000 + 50;
 
int cnt[N];
 
int main() {
    int n, Max = 0;
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        Max = max(Max, x);
        ++cnt[x];
    }
    for (int i = Max; i; --i) {
        if (cnt[i] && !cnt[i + 1]) {
            --cnt[i];
            ++cnt[i + 1];
        }
    }
    for (int i = 2; i <= Max; ++i) {
        if (cnt[i] && !cnt[i - 1]) {
            --cnt[i];
            ++cnt[i - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= Max + 1; ++i) {
        ans += !!cnt[i];
    }
    printf("%d\n", ans);
    return 0;
}