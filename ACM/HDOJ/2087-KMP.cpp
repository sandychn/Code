/*
 * @Author: Sandy 
 * @Date: 2019-07-26 21:52:00
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-08-08 22:13:53
 */

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

int kmpSearch(char *s, char *t, int sLen, int tLen, int *tNext) {
    int ans = 0, last = 0; // last 记录完整出现位置
    for (int i = 1, j = 0; i <= sLen; ++i) {
        while (j > 0 && (j == tLen || s[i] != t[j + 1])) j = tNext[j];
        f[i] = (s[i] == t[j + 1]) ? ++j : j;
        if (f[i] == tLen) {
            if (i - last >= tLen) { // 有重叠
                ++ans;
                last = i;
            }
        }
    }
    return ans;
}

int main() {
    while (~scanf("%s", s + 1)) {
        if (s[1] == '#') break;
        scanf("%s", t + 1);
        int sLen = strlen(s + 1), tLen = strlen(t + 1);
        calcNext(t, nxt, tLen);
        printf("%d\n", kmpSearch(s, t, sLen, tLen, nxt));
    }
    return 0;
}