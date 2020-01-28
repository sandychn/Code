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

// const int INF = 0x3F3F3F3F;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;
// const int N = 405;

int need[3];
int have[3];
int price[3];

int main() {
    string s;
    LL money;
    cin >> s;
    for (char ch : s) {
        if (ch == 'B') {
            ++need[0];
        } else if (ch == 'S') {
            ++need[1];
        } else {
            ++need[2];
        }
    }
    for (int i = 0; i < 3; ++i) cin >> have[i];
    for (int i = 0; i < 3; ++i) cin >> price[i];
    cin >> money;
    LL l = -1, r = 1e15 + 10;
    while (l + 1 < r) {
        LL mid = (l + r) >> 1;
        LL cost = 0;
        for (int i = 0; i < 3; ++i) {
            if (need[i] * mid > have[i]) {
                cost += (need[i] * mid - have[i]) * price[i];
            }
        }
        if (cost > money) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}