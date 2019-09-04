#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x)                                                    \
    cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in " \
         << __FUNCTION__ << ")\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() {
        cerr << "\nTime: " << int(1000.0 * clock() / CLOCKS_PER_SEC) << " ms\n";
    }
} _tester;
#else
#define show(x)
#endif

bool isPrime(int n) {
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, ans = 0;
    cin >> n;
    if (n == 2 || n == 3 || isPrime(n)) {
        ans = 1;
    } else if (n % 2 == 0) {
        // for every even number x >= 2, is a sum of 2 prime numbers.
        ans = 2;
    } else if (isPrime(n - 2)) {
        // for every odd number x > 3, x = 2 + (x - 2)
        // if (x - 2) is a prime number, the answer will be 2.
        ans = 2;
    } else {
        // for every odd number x > 3, x = 3 + (x - 3)
        // (x - 3) is an even number, and it is a sum of 2 prime numbers.
        // so the answer is 3.
        ans = 3;
    }
    cout << ans;
    return 0;
}