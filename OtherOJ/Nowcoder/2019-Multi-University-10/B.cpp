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

LL len[550];
const string str[] = {"!COFFEE", "!CHICKEN"};

// COFFEE CHICKEN

void print(int n, LL k, int count) {
    if (n == 1) {
        for (int i = k; i <= 6 && i <= k + count - 1; ++i) {
            putchar(str[0][i]);
        }
        return;
    }
    if (n == 2) {
        for (int i = k; i <= 7 && i <= k + count - 1; ++i) {
            putchar(str[1][i]);
        }
        return;
    }
    if (n >= 60) {
        print(n - 2, k, count);
        return;
    }
    LL left = len[n - 2];
    if (k + count <= left) {
        print(n - 2, k, count);
    } else if (k > left) {
        print(n - 1, k - left, count);
    } else {
        print(n - 2, k, left - k + 1);
        print(n - 1, 1, count - (left - k + 1));
    }
}

int main() {
    len[1] = 6;
    len[2] = 7;
    for (int i = 3; i <= 60; ++i) {
        len[i] = len[i - 1] + len[i - 2];
    }
    int T;
    scanf("%d", &T);
    while (T--){
        int n;
        LL k;
        scanf("%d%lld", &n, &k);
        print(n, k, 10);
        putchar('\n');
    }
    return 0;
}