// 2019-04-03
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int INF = 0x3F3F3F3F;
const int N = 35, M = 5050;

// dp[i][j] 表示 前i个孩子一共分配j块饼干时 这i个孩子的怒气总和的最小值
// p数组和q数组用于存储路径
// 若 dp[i][j] 是从 dp[x][y] 转移来的, 则 p[i][j] = x, q[i][j] = y

int sum[N], dp[N][M], p[N][M], q[N][M], ans[N];

struct Node {
    int num, id;
    bool operator<(const Node &b) const { return this->num > b.num; }
} a[N];

void makeAns(int child, int cookie) {
    if (child == 0) return;
    makeAns(p[child][cookie], q[child][cookie]);
    if (p[child][cookie] == child) {
        for (int i = 1; i <= child; ++i) ++ans[a[i].id];
    } else {
        for (int i = p[child][cookie] + 1; i <= child; ++i) ans[a[i].id] = 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].num, a[i].id = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i].num;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= m; ++j) {
            dp[i][j] = dp[i][j - i];
            p[i][j] = i, q[i][j] = j - i;
            for (int k = 0; k < i; ++k) {
                int val = dp[k][j - (i - k)] + k * (sum[i] - sum[k]);
                if (dp[i][j] > val) {
                    dp[i][j] = val;
                    p[i][j] = k, q[i][j] = j - (i - k);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
    makeAns(n, m);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
    return 0;
}
