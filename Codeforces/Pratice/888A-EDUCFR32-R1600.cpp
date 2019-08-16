#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("../sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

const int N = 1050;

int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int res = 0;
    for (int i = 2; i < n; ++i) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) ++res;
        else if (a[i] > a[i - 1] && a[i] > a[i + 1]) ++res;
    }
    cout << res;
    return 0;
}