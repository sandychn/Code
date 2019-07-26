// 2019-02-21
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
#include <vector>

using namespace std;
typedef long long LL;
const int INF = 0x3F3F3F3F;
const LL LLINF = 0x3F3F3F3F3F3F3F3FLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int MAXN = 300000 + 10;

int a[MAXN];
long long sum[MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];
    deque<int> q;
    LL ans = a[1];
    q.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && i - q.front() > m)
            q.pop_front();
        ans = max(ans, sum[i] - sum[q.front()]);
        while (!q.empty() && sum[q.back()] >= sum[i])
            q.pop_back();
        q.push_back(i);
    }
    printf("%lld\n", ans);
    return 0;
}
