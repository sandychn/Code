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
#include <vector>

using namespace std;
typedef long long LL;
const int INF = 0x3F3F3F3F;
const LL LLINF = 0x3F3F3F3F3F3F3F3FLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int MAXN = 1e5 + 10;

int a[MAXN];

int main() {
    int n, m, q, u, v, t;
    double p;
    scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
    p = double(u) / v;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    queue<int> que[3];
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; ++i) {
        que[0].push(a[i]);
    }
    int delta = 0;
    for (int i = 1; i <= m; ++i) {
        int id = -1;
        for (int j = 0; j < 3; ++j) {
            if (que[j].empty()) continue;
            if (id == -1 || que[id].front() < que[j].front()) id = j;
        }
        int val = que[id].front() + delta;
        que[id].pop();
        if (i % t == 0) {
            if (i != t) printf(" ");
            printf("%d", val);
        }
        que[1].push(floor(p * val) - delta - q);
        que[2].push(val - floor(p * val) - delta - q);
        delta += q;
    }
    puts("");
    for (int i = 1; i <= n + m; ++i) {
        int id = -1;
        for (int j = 0; j < 3; ++j) {
            if (que[j].empty()) continue;
            if (id == -1 || que[id].front() < que[j].front()) id = j;
        }
        int val = que[id].front() + delta;
        que[id].pop();
        if (i % t == 0) {
            if (i != t) printf(" ");
            printf("%d", val);
        }
    }
    puts("");
    return 0;
}
