/*
 * @Author: Sandy 
 * @Date: 2019-07-26 23:23:24 
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-26 23:40:59
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
const int MOD = 10007;

char s[N];
int nxt[N];  // next[i] 表示“A中以i结尾的非前缀子串”与“A的前缀”能够匹配的最长长度
int ans;

void calcNext(char *t, int *nxt, int len) {
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= len; ++i) {
        while (j > 0 && t[i] != t[j + 1]) j = nxt[j];
        nxt[i] = (t[i] == t[j + 1]) ? ++j : j;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int len;
        ans = 0;
        scanf("%d%s", &len, s + 1);
        calcNext(s, nxt, len);

        // todo...

        printf("%d\n", ans);
    }

    return 0;
}