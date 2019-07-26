// 2019-02-11
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 105;

int a[MAXN][MAXN], sum[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) { // 行上边界
            memset(sum, 0, sizeof(sum));
            for (int j = i; j <= n; ++j) { // 行下边界
                int s = 0;
                for (int k = 1; k <= n; ++k) { // 在sum上求最大区间和
                    sum[k] += a[j][k];
                    s += sum[k];
                    if (s < 0) s = 0;
                    ans = max(ans, s);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
