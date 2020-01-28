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

int main() {
    int n;
    scanf("%d", &n);
    vector<bool> neg;
    vector<pair<int, int>> v;
    char buf[666];
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%s", buf);
        sscanf(buf, "%d.%d", &a, &b);
        neg.push_back(*buf == '-');
        v.emplace_back(a, b);
        sum += a;
    }
    if (sum < 0) {
        sum = -sum;
        for (int i = 0; i < n && sum; ++i) {
            if (v[i].second == 0) continue;
            if (neg[i]) continue;
            ++v[i].first;
            --sum;
        }
    } else if (sum > 0) {
        for (int i = 0; i < n && sum; ++i) {
            if (v[i].second == 0) continue;
            if (!neg[i]) continue;
            --v[i].first;
            --sum;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", v[i].first);
    }
    return 0;
}