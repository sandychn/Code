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

const int N = 105;
int a[N], b[N];
set<int> sa, sb;

int main() {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sa.insert(a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        sa.insert(b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!sa.count(a[i] + b[j]) && !sb.count(a[i] + b[j])) {
                cout << a[i] << ' ' << b[j];
                return 0;
            }
        }
    }

    return 0;
}