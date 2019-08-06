/*
Solution for Luogu-3809
字符串长度 1e6
std::sort版后缀数组, TLE (time > 3000 MS)
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 50;

char s[N];
int sa[N], rk[N], height[N];
int tmp[N];

struct CompSA {
    int len, k;

    bool operator()(const int i, const int j) {
        if (rk[i] != rk[j]) return rk[i] < rk[j];
        int ri = i + k <= len ? rk[i + k] : -1;
        int rj = j + k <= len ? rk[j + k] : -1;
        return ri < rj;
    }
} compSA;

void calcSA(char *s) {
    for (int i = 1; i <= compSA.len; ++i) rk[i] = s[i], sa[i] = i;
    for (compSA.k = 1; compSA.k <= compSA.len; compSA.k <<= 1) {
        sort(sa + 1, sa + compSA.len + 1, compSA);
        tmp[sa[1]] = 1;
        for (int i = 1; i < compSA.len; ++i)
            tmp[sa[i + 1]] = tmp[sa[i]] + compSA(sa[i], sa[i + 1]);
        for (int i = 1; i <= compSA.len; ++i) rk[i] = tmp[i];
    }
    for (int i = 1; i <= compSA.len; ++i) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= compSA.len; ++i) {
        if (rk[i] == 1) {
            height[rk[i]] = 0;
        } else {
            if (k) --k;
            for (int j = sa[rk[i] - 1]; i + k <= compSA.len && j + k <= compSA.len && s[i + k] == s[j + k]; ++k)
                ;
            height[rk[i]] = k;
        }
    }
}

int main() {
    scanf("%s", s + 1);
    compSA.len = strlen(s + 1);
    calcSA(s);
    for (int i = 1; i <= compSA.len; ++i) printf("%d ", sa[i]);
    return 0;
}