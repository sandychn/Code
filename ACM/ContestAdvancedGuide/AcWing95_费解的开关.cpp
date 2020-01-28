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
const int MAXN = 10;

int mp[MAXN], t[MAXN];

void init() {
    for (int i = 1; i <= 5; ++i)
        t[i] = mp[i];
}

void change(int x, int y) {
    static const int dx[] = {0, 0, 0, -1, 1};
    static const int dy[] = {0, -1, 1, 0, 0};
    for (int i = 0; i < 5; ++i) {
        t[x + dx[i]] ^= (1 << (y + dy[i]));
    }
}

int main() {
    int n; scanf("%d", &n);
    char buf[10];
    while (n--) {
        for (int i = 1; i <= 5; ++i) {
            scanf("%s", buf);
            mp[i] = 0;
            for (int j = 0; j < 5; ++j) {
                mp[i] = (mp[i] << 1) + buf[j] - '0';
            }
            mp[i] <<= 1; // move to bits from #1 to #5
        }
        int ans = 7;
        for (int i = 0; i < 1 << 5; ++i) {
            init();
            int step = 0;
            for (int j = 0; j < 5; ++j) {
                if (i >> j & 1)
                    change(1, j + 1), ++step;
            }
            for (int x = 2; x <= 5 && step < ans; ++x) {
                for (int y = 1; y <= 5 && step < ans; ++y) {
                    if (!(t[x - 1] >> y & 1)) {
                        change(x, y);
                        ++step;
                    }
                }
            }
            if (step >= ans) continue;
            bool ok = true;
            for (int y = 1; y <= 5 && ok; ++y)
                if (!(t[5] >> y & 1))
                    ok = false;
            if (ok) ans = step;
        }
        printf("%d\n", ans > 6 ? -1 : ans);
    }
    return 0;
}
