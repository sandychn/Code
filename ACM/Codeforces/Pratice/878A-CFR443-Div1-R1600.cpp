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
 
const int N = 10;
const int UNKNOWN = 0;
const int ONE = 1;
const int ZERO = 2;
const int ONCE = 3;  // xor once
 
int f[N + 5];
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char ch;
        int val;
        cin >> ch >> val;
        if (ch == '|') {
            for (int i = 0; i < N; ++i) {
                int v = (val >> i) & 1;
                if (v) f[i] = ONE;
            }
        } else if (ch == '&') {
            for (int i = 0; i < N; ++i) {
                int v = (val >> i) & 1;
                if (v == 0) f[i] = ZERO;
            }
        } else {
            for (int i = 0; i < N; ++i) {
                int v = (val >> i) & 1;
                if (v) {
                    if (f[i] == UNKNOWN) f[i] = ONCE;
                    else if (f[i] == ONE) f[i] = ZERO;
                    else if (f[i] == ZERO) f[i] = ONE;
                    else if (f[i] == ONCE) f[i] = UNKNOWN;
                }
            }
        }
    }
    int AND = 1023, OR = 0, XOR = 0;
    for (int i = 0; i < 10; ++i) {
        if (f[i] == ONE) OR |= (1 << i);
        else if (f[i] == ZERO) AND ^= (1 << i);
        else if (f[i] == ONCE) XOR |= (1 << i);
    }
    cout << (AND != 1023) + (OR != 0) + (XOR != 0) << endl;
    if (AND != 1023) cout << "& " << AND << endl;
    if (OR) cout << "| " << OR << endl;
    if (XOR) cout << "^ " << XOR << endl;
    return 0;
}
