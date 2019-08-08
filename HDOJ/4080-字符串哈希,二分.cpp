/*
 * @Author: Sandy 
 * @Date: 2019-08-08 23:00:00
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-08-09 01:16:27
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#ifdef _LOCAL
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#endif

const int N = 40050;
const int SEED = 131;

int m, len;
char str[N];
ULL h[N], base[N];
pair<ULL, int> keys[N];
// first: 哈希值
// second: 出现的开头位置

void initBase() {
    base[0] = 1;
    for (int i = 1; i < N; ++i) base[i] = base[i - 1] * SEED;
}

inline ULL getHash(int first, int last) {  // 子串 [first, last] 的哈希值
    return h[last] - h[first - 1] * base[last - first + 1];
}

int check(int mid) {
    int tot = 0;
    for (int i = 1; i + mid - 1 <= len; ++i) {
        ULL key = getHash(i, i + mid - 1);
        keys[tot].first = key, keys[tot].second = i;
        ++tot;
    }
    sort(keys, keys + tot);
    int ans = -1, cnt = 0;
    for (int i = 0; i < tot; ++i) {
        if (!i || keys[i].first == keys[i - 1].first) {
            ++cnt;
        } else {
            cnt = 1;
        }
        if (cnt >= m) ans = max(ans, keys[i].second);
    }
    return ans;
}

int main() {
    initBase();
    while (~scanf("%d", &m) && m) {
        scanf("%s", str + 1);
        len = strlen(str + 1);
        for (int i = 1; i <= len; ++i) h[i] = h[i - 1] * SEED + str[i];
        int l = -1, r = len + 1;  // 二分答案的长度
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(mid) != -1) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == 0) {
            puts("none");
        } else {
            printf("%d %d\n", l, check(l) - 1);
        }
    }
    return 0;
}