/*
 * @Author: Sandy 
 * @Date: 2019-07-29 15:00:56 
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-30 15:51:15
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#if __cplusplus >= 201103L
#include <chrono>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

int a[N], b[N], n, m, tot;

struct BIT {
    LL t[N];
    void clear() {
        for (int i = 0; i <= n; ++i) t[i] = 0;
    }
    int lowbit(int x) {
        return x & -x;
    }
    LL ask(int x) {
        LL sum = 0;
        for (; x; x -= lowbit(x)) sum += t[x];
        return sum;
    }
    void add(int x, LL val) {
        for (; x <= n; x += lowbit(x)) t[x] += val;
    }
} bit, bit2;

int getId(int val) {
    return lower_bound(b + 1, b + tot, val) - b;
}

void compress() {
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - b;
}

int main() {
#ifdef _LOCAL
    freopen("test.in", "r", stdin);
#endif

    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i), b[i] = a[i];
        }

        bit.clear();
        bit2.clear();
        compress();

        LL sum = a[1];
        int id_1 = getId(a[1]);
        bit.add(id_1, a[1]);
        bit2.add(id_1, 1);
        printf("0 ");

        for (int i = 2; i <= n; ++i) {
            sum += a[i];
            int l = -1, r = n + 1;
            LL ask_n = bit.ask(n);
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                LL val = ask_n - bit.ask(mid);
                if (val >= sum - m) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            LL right = bit2.ask(n), left = bit2.ask(l);
            if (left == right) {
                printf("0 ");
            } else {
                LL left_plus_one = bit2.ask(l + 1);
                LL summ = ask_n - bit.ask(l + 1);
                LL remain = sum - m - summ;
                printf("%d ", int(right - left_plus_one + (remain + b[l + 1] - 1) / b[l + 1]));
            }
            int id = getId(a[i]);
            bit.add(id, a[i]);
            bit2.add(id, 1);
        }
        puts("");
    }

#ifdef _LOCAL
    fprintf(stderr, "\nTime elapsed: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC));
#endif
    return 0;
}