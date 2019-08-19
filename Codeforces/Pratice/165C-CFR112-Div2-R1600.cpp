#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() {
        freopen("sample.in", "r", stdin);
        // freopen("out.out", "w", stdout);
    }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

const int N = 1e6 + 10;

char s[N];
int sum[N];

int main() {
    int k;
    cin >> k >> (s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
        sum[i] = sum[i - 1] + (s[i] == '1');
    }
    LL ans = 0;
    for (int i = 1; i <= len; ++i) {
        int l = i - 1, r = len + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (sum[mid] - sum[i - 1] > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        int ll = i - 1, rr = len + 1;
        while (ll + 1 < rr) {
            int mid = (ll + rr) >> 1;
            if (sum[mid] - sum[i - 1] < k) {
                ll = mid;
            } else {
                rr = mid;
            }
        }
        // printf("%d %d %d %d %d\n", i, l, r, ll, rr);
        ans += l - rr + 1;
    }
    cout << ans << endl;
    return 0;
}