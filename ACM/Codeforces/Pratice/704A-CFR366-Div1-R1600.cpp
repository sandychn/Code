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

const int N = 300050;

int cnt[N], read[N], last[N];
pair<int, int> all[N];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int total = 0, ans = 0;
    int all_read = 0;
    for (int i = 1; i <= q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1) {
            ++total;
            all[total] = {b, total};
            ++cnt[b];
            ++ans;
        } else if (a == 2) {
            ans -= cnt[b] - read[b];
            read[b] = cnt[b];
            last[b] = total;
        } else {
            for (int j = all_read + 1; j <= b; ++j) {
                int id = all[j].first;
                int time = all[j].second;
                if (last[id] >= time) continue; // have read.
                --ans;
                ++read[id];
            }
            all_read = max(all_read, b);
        }
        printf("%d\n", ans);
    }
    return 0;
}