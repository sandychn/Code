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
const int N = 2e5 + 50;

vector<int> v;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), ans = 0;
    v.push_back(-1);
    for (int i = 0, j = 0; i < n && j < m; ++i) {
        if (s[i] == t[j]) {
            ans = max(ans, i - v.back() - 1);
            v.push_back(i);
            ++j;
        }
    }
    ans = max(ans, n - 1 - v.back());
    for (int i = n - 1, j = m - 1; ~i && ~j; --i) {
        if (s[i] == t[j]) {
            ans = max(ans, i - v[j] - 1);
            --j;
        }
    }
    cout << ans << endl;
    return 0;
}