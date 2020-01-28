// 2019-02-14
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;
typedef long long LL;
const int INF = 0x3F3F3F3F;
const LL LLINF = 0x3F3F3F3F3F3F3F3FLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int MAXN = 1e6 + 10;

template<typename T>
void out(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) out(x / 10);
    putchar(x % 10 | 48);
}

template<typename T>
bool in(T &x) {
    bool neg = false; char c;
    while (c = getchar(), c < 48 || c > 57) {
        c == '-' && (neg = !neg);
        if (c == EOF) return false;
    }
    for (x = c ^ 48; c = getchar(), c >= 48 && c <= 57; x = (x << 1) + (x << 3) + (c ^ 48));
    neg && (x = -x);
    return true;
}

int a[MAXN], ansMin[MAXN], ansMax[MAXN];
struct Node {
    int value, pos;
} qMin[MAXN], qMax[MAXN];
int minFront, minBack, maxFront, maxBack;

int main() {
    int n, k;
    in(n), in(k);
    for (int i = 1; i <= n; ++i) in(a[i]);
    minFront = maxFront = minBack = maxBack = 1;
    for (int i = 1; i <= k; ++i) {
        while (minFront < minBack && qMin[minBack - 1].value >= a[i]) --minBack;
        qMin[minBack++] = {a[i], i};
        while (maxFront < maxBack && qMax[maxBack - 1].value <= a[i]) --maxBack;
        qMax[maxBack++] = {a[i], i};
    }
    ansMin[k] = qMin[minFront].value, ansMax[k] = qMax[maxFront].value;
    for (int i = k + 1; i <= n; ++i) {
        while (minFront < minBack && i - qMin[minFront].pos >= k) ++minFront;
        while (minFront < minBack && qMin[minBack - 1].value >= a[i]) --minBack;
        qMin[minBack++] = {a[i], i};
        while (maxFront < maxBack && i - qMax[maxFront].pos >= k) ++maxFront;
        while (maxFront < maxBack && qMax[maxBack - 1].value <= a[i]) --maxBack;
        qMax[maxBack++] = {a[i], i};
        ansMin[i] = qMin[minFront].value, ansMax[i] = qMax[maxFront].value;
    }
    out(ansMin[k]);
    for (int i = k + 1; i <= n; ++i) putchar(' '), out(ansMin[i]);
    putchar('\n');
    out(ansMax[k]);
    for (int i = k + 1; i <= n; ++i) putchar(' '), out(ansMax[i]);
    putchar('\n');
    return 0;
}