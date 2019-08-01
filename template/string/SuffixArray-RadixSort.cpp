#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const int N = 100000 * 2 + 50;
const int M = 150;

char s[N];
int sa[N], rk[N], height[N], cnt[M], t1[N], t2[N];

void calcSA(char *s, int n) {
    int m = 128;
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
}

void calcHeight(char *s, int n) {
    int i, j, k;
    for (i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 1) {
            height[rk[i]] = 0;
        } else {
            if (k) --k;
            j = sa[rk[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
            height[rk[i]] = k;
        }
    }
}

int main() {
#ifdef _LOCAL
    freopen("sample.in", "r", stdin);
#endif
    while (~scanf("%s", s + 1)) {
        int len1 = strlen(s + 1);
        s[len1 + 1] = '$';
        scanf("%s", s + len1 + 2);
        int len2 = strlen(s + len1 + 2);
        calcSA(s, len1 + len2 + 1);
        calcHeight(s, len1 + len2 + 1);
        int ans = 0;
        for (int i = 2; i <= len1 + len2 + 1; ++i) {
            if (height[i] <= ans) continue;
            if ((sa[i - 1] <= len1 && sa[i] > len1 + 1) || (sa[i - 1] > len1 + 1 && sa[i] <= len1))
                ans = height[i];
        }
        printf("%d\n", ans);
    }
#ifdef _LOCAL
    fprintf(stderr, "Time elapsed: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC));
#endif
    return 0;
}