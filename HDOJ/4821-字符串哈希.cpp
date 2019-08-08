/*
 * @Author: Sandy 
 * @Date: 2019-08-08 22:13:05 
 * @Last Modified by:   Sandy 
 * @Last Modified time: 2019-08-08 22:13:05 
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 1e5 + 50;
const int SEED = 131;

char s[N];
ULL h[N], base[N];
unordered_map<ULL, int> mp;

void initBase() {
    base[0] = 1;
    for (int i = 1; i < N; ++i) base[i] = base[i - 1] * SEED;
}

ULL getHash(int first, int last) {  // 子串 [first, last] 的哈希值
    return (h[last] - h[first - 1] * base[last - first + 1]);
}

int main() {
    initBase();
    int m, l;
    while (~scanf("%d%d%s", &m, &l, s + 1)) {
        int len = strlen(s + 1);
        for (int i = 1; i <= len; ++i) h[i] = h[i - 1] * SEED + s[i];
        int ans = 0;
        for (int start = 1; start <= l; ++start) {
            int moreThanOne = 0;
            mp.clear();
            for (int i = 0; i < m - 1; ++i) {
                ULL key = getHash(start + i * l, start + (i + 1) * l - 1);
                if (++mp[key] == 2) ++moreThanOne;
            }
            for (int i = m - 1; start + (i + 1) * l - 1 <= len; ++i) {
                ULL key = getHash(start + i * l, start + (i + 1) * l - 1);
                if (++mp[key] == 2) ++moreThanOne;
                if (!moreThanOne) ++ans;
                ULL pre = getHash(start + (i - m + 1) * l, start + (i + 1 - m + 1) * l - 1);
                int cnt = --mp[pre];
                if (cnt == 1) {
                    --moreThanOne;
                } else if (cnt == 0) {
                    mp.erase(cnt);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
