// 2019-02-15
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
const int MAXN = 100050;

pair<LL, LL> st[MAXN]; // height, width
LL a[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
        a[n + 1] = 0;
        LL ans = 0;
        int top = 0;
        for (int i = 1; i <= n + 1; ++i) {
            LL width = 0;
            while (top && st[top].first >= a[i]) {
                width += st[top].second;
                ans = max(ans, st[top].first * width);
                --top;
            }
            st[++top] = {a[i], width + 1};
        }
        printf("%lld\n", ans);
    }
    return 0;
}
