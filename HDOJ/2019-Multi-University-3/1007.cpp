/*
 * @Author: Sandy 
 * @Date: 2019-07-29 15:00:56 
 * @Last Modified by:   Sandy 
 * @Last Modified time: 2019-07-29 15:00:56 
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

template <typename T>
inline void read(T &x) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    x = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
}

template <typename T>
void print(T x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int a[N], n, m;
int b[N];
unordered_map<int, int> val_id;

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

void compress() {
    sort(b + 1, b + n + 1);
    int tot = unique(b + 1, b + n + 1) - b;
    for (int i = 1; i < tot; ++i) {
        int val = b[i];
        val_id[val] = i;
    }
}

int main() {
#ifdef _LOCAL
    freopen("test.in", "r", stdin);
#endif

    int q;
    scanf("%d", &q);
    while (q--) {
        read(n), read(m);
        for (int i = 1; i <= n; ++i) {
            read(a[i]), b[i] = a[i];
        }

        val_id.clear();
        bit.clear();
        bit2.clear();
        compress();

        LL sum = a[1];
        int id_1 = val_id[a[1]];
        bit.add(id_1, a[1]);
        bit2.add(id_1, 1);
        putchar('0'), putchar(' ');

        for (int i = 2; i <= n; ++i) {
            sum += a[i];
            int l = -1, r = n + 1;
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                LL val = bit.ask(n) - bit.ask(mid);
                if (val >= sum - m) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            LL right = bit2.ask(n), left = bit2.ask(l);
            if (left == right) {
                putchar('0');
            } else {
                LL left_plus_one = bit2.ask(l + 1);
                LL summ = bit.ask(n) - bit.ask(l + 1);
                LL remain = sum - m - summ;
                print(int(right - left_plus_one + (remain + b[l + 1] - 1) / b[l + 1]));
            }
            putchar(' ');
            int id = val_id[a[i]];
            bit.add(id, a[i]);
            bit2.add(id, 1);
        }
        putchar('\n');
    }

#ifdef _LOCAL
    fprintf(stderr, "\nTime elapsed: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC));
#endif
    return 0;
}