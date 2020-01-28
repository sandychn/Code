#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

using namespace std;
using LL = long long;
const int INF = 1 << 30;
const int N = 505;
const int MAX = 1e6;

map<LL, vector<pair<int, int>>> mp;
int a[N];
int zero[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        zero[i] = zero[i - 1] + !a[i];
    }
    for (int k = 3; k <= n; ++k) {
        for (int p = k + 1; p <= n; ++p) {
            if (a[k] && a[p] % a[k] == 0) {
                mp[a[p] / a[k]].emplace_back(k, p);
            }
        }
    }
    LL ans = 0;
    for (int k = 3; k < n; ++k) {
        if (a[k] == 0) {
            ans += 1LL * (zero[n] - zero[k]) * (k - 1) * (k - 2) / 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (1LL * a[i] * a[j] > MAX) continue;
            auto it = mp.find(1LL * a[i] * a[j]);
            if (it == mp.end()) continue;
            vector<pair<int, int>> &v = it->second;
            ans += v.end() - lower_bound(v.begin(), v.end(), make_pair(j + 1, j + 2));
        }
    }
    printf("%lld\n", ans);
    return 0;
}