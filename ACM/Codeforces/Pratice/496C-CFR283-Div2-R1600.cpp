#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

const int N = 105;

char s[N][N];
int diff[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        bool del = false;
        for (int i = 0; i < n - 1; ++i) {
            if (!diff[i] && s[i][j] > s[i + 1][j]) {
                del = true;
                break;
            }
        }
        if (del) ++ans;
        else {
            for (int i = 0; i < n - 1; ++i) {
                if (s[i][j] != s[i + 1][j]) diff[i] = true;
            }
        }
    }
    cout << ans;
    return 0;
}