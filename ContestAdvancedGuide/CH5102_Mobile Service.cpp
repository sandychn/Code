// 2019-03-28
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXL = 205;
const int MAXN = 1005;
const int INF = 0x3F3F3F3F;

int cost[MAXL][MAXL], pos[MAXN];
int dp[MAXN][MAXL][MAXL];

int main(int argc, char const *argv[]) {
    
    int l, n;
    cin >> l >> n;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= l; ++j) {
            cin >> cost[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) cin >> pos[i];
    
    memset(dp, 0x3F, sizeof(dp));
    dp[0][1][2] = 0; // waiter at (x=1, y=2, z=3)
    pos[0] = 3;

    for (int i = 0; i < n; ++i) {
        for (int x = 1; x <= l; ++x) {
            for (int y = 1; y <= l; ++y) {
                int now = pos[i], nex = pos[i + 1];
                if (x != y && y != nex && x != nex)
                    dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y] + cost[now][nex]); // (x, y, now->nex)
                if (x != now && x != nex && nex != now)
                    dp[i + 1][x][now] = min(dp[i + 1][x][now], dp[i][x][y] + cost[y][nex]); // (x, y->nex, now)
                if (nex != y && y != now && nex != now)
                    dp[i + 1][now][y] = min(dp[i + 1][now][y], dp[i][x][y] + cost[x][nex]); // (x->nex, y, now)
            }
        }
    }
    
    int ans = INF;
    for (int x = 1; x <= l; ++x) {
        for (int y = 1; y <= l; ++y) {
            ans = min(ans, dp[n][x][y]);
        }
    }
    cout << ans << endl;

    return 0;
}