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
 
const int N = 10005;
 
int a[N];
int pos[N];
 
bool check1(int n) {
    int x = pos[1];
    for (int i = 1; i <= n; ++i) {
        if (pos[i] != x) return false;
        x = x + 1;
        if (x > n) x = 1;
    }
    return true;
}
 
bool check2(int n) {
    int x = pos[1];
    for (int i = 1; i <= n; ++i) {
        if (pos[i] != x) return false;
        x = x - 1;
        if (x < 1) x = n;
    }
    return true;
}
 
int main() {
    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            pos[x] = i;
        }
        if (check1(n) || check2(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}