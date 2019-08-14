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
 
const int N = 4e5 + 50;
 
bool check(const string &s, const string &t) {
    int match = 0;
    for (int i = 0; i < s.size() && match < t.size(); ++i) {
        if (s[i] == t[match]) ++match;
    }
    return match == t.size();
}
 
int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < int(s.size()); ++i) {
        for (int j = i; j < int(s.size()); ++j) {
            string tmp = s;
            tmp.erase(tmp.begin() + i, tmp.begin() + j + 1);
            if (check(tmp, t)) ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}