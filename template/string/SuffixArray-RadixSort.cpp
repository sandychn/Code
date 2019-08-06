/*
Solution for Luogu-3809
字符串长度 1e6
基数排序版后缀数组, 945 MS, 24.39 MB
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 50;

char s[N];
int sa[N], rk[N], cnt[N], height[N], t1[N], t2[N];

void calcSA(char *s, int n) {
    int m = 256;
    int i, *x = t1, *y = t2;
    for (i = 1; i <= m; ++i) cnt[i] = 0;
    for (i = 1; i <= n; ++i) ++cnt[x[i] = s[i]];
    for (i = 2; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k + 1; i <= n; ++i) y[++p] = i;
        for (i = 1; i <= n; ++i)
            if (sa[i] > k) y[++p] = sa[i] - k;
        for (i = 1; i <= m; ++i) cnt[i] = 0;
        for (i = 1; i <= n; ++i) ++cnt[x[i]];
        for (i = 2; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[x[y[i]]]--] = y[i];
        swap(x, y);
        x[sa[1]] = 1;
        p = 1;
        for (i = 2; i <= n; ++i)
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]) ? p : ++p;
        if (p >= n) break;
        m = p;
    }
    for (i = 1; i <= n; ++i) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 1) {
            height[rk[i]] = 0;
        } else {
            if (k) --k;
            int j = sa[rk[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
            height[rk[i]] = k;
        }
    }
}

int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    calcSA(s, len);
    for (int i = 1; i <= len; ++i) printf("%d ", sa[i]);
    return 0;
}