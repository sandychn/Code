/*
 * @Author: Sandy
 * @Date: 2019-07-27 21:51:55
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-28 17:10:15
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
const int MOD = 10007;

char s[N];
int nxt[N];  // next[i] 表示A中以i结尾的非前缀子串与A的前缀能匹配的最长长度
int dp[N];

void calcNext(char *t, int *nxt, int len) {
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= len; ++i) {
        while (j > 0 && t[i] != t[j + 1]) j = nxt[j];
        nxt[i] = (t[i] == t[j + 1]) ? ++j : j;
    }
}

int main() {
#ifdef _LOCAL
    freopen("test.in", "r", stdin);
#endif
    int T, len;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &len, s + 1);
        calcNext(s, nxt, len);
        int ans = 0;
        for (int i = 1; i <= len; ++i) {
            dp[i] = dp[nxt[i]] + 1;
            ans = (ans + dp[i]) % MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}