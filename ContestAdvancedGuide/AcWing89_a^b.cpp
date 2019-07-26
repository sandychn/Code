// 2019-01-31
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int dp[1 << 20][20];
int dist[20][20];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &dist[i][j]);
        }
    }
    memset(dp, 0x3F, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) { // going to j
                for (int k = 0; k < n; ++k) {
                    int pre = i ^ 1 << j;
                    if (pre >> k & 1) {
                        dp[i][j] = std::min(dp[i][j], dp[pre][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1][n - 1]);
    return 0;
}