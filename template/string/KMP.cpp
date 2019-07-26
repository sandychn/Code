/*
 * @Author: Sandy 
 * @Date: 2019-07-26 22:05:30 
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-26 23:14:19
 */

// Complexity: O(N + M)

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1e6 + 10;

char s[N], t[N];
// B是主串，A是模式串
int nxt[N];  // next[i] 表示“A中以i结尾的非前缀子串”与“A的前缀”能够匹配的最长长度
int f[N];  // f[i] 表示“B中以i结尾的子串”与“A的前缀”能够匹配的最长长度

void calcNext(char *t, int *nxt, int len) {
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= len; ++i) {
        while (j > 0 && t[i] != t[j + 1]) j = nxt[j];
        nxt[i] = (t[i] == t[j + 1]) ? ++j : j;
    }
}

// s.find(t)
int kmpSearch(char *s, char *t, int sLen, int tLen, int *tNext) {
    int ans = sLen + 5;
    for (int i = 1, j = 0; i <= sLen; ++i) {
        while (j > 0 && (j == tLen || s[i] != t[j + 1])) j = tNext[j];
        f[i] = (s[i] == t[j + 1]) ? ++j : j;
        if (f[i] == tLen) ans = min(ans, i - tLen + 1);  // t在s中完整出现一次
    }
    return ans;
}

int main() {
    while (~scanf("%s%s", s + 1, t + 1)) {
        int sLen = strlen(s + 1), tLen = strlen(t + 1);
        calcNext(t, nxt, tLen);
        int ans = kmpSearch(s, t, sLen, tLen, nxt);
        if (ans > sLen) ans = 0;
        printf("%d\n", --ans);
    }
    return 0;
}
