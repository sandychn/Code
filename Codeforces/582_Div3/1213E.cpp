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

string str[3] = {"a", "b", "c"};

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    bool ok = 0;
    if (n == 1) {
        do {
            string ans = str[0] + str[1] + str[2];
            if (ans.find(s) != string::npos || ans.find(t) != string::npos) continue;
            cout << "YES\n"
                 << ans << endl;
            ok = 1;
            break;
        } while (next_permutation(str, str + 3));
    } else {
        do {
            string t1 = str[0] + str[1], t2 = str[1] + str[2];
            string t3 = str[1] + str[0], t4 = str[2] + str[2];
            if (s == t1 || s == t2 || s == t3 || s == t4) continue;
            if (t == t1 || t == t2 || t == t3 || t == t4) continue;
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << str[0] << str[1];
            for (int i = 0; i < n; ++i) cout << str[2];
            cout << endl;
            ok = 1;
            break;
        } while (next_permutation(str, str + 3));

        if (!ok) {
            do {
                string t1 = str[0] + str[0], t2 = str[0] + str[1];
                string t3 = str[1] + str[2], t4 = str[2] + str[1];
                if (s == t1 || s == t2 || s == t3 || s == t4) continue;
                if (t == t1 || t == t2 || t == t3 || t == t4) continue;
                cout << "YES\n";
                for (int i = 0; i < n; ++i) cout << str[0];
                for (int i = 0; i < n; ++i) cout << str[1] << str[2];
                cout << endl;
                ok = 1;
                break;
            } while (next_permutation(str, str + 3));
        }
    }
    if (!ok) cout << "NO\n";  // won't happen
    return 0;
}
