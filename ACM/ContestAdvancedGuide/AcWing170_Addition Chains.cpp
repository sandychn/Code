// 2019-04-13
#include <stdio.h>
#include <string.h>

const int N = 105;
int n, len, a[N];
bool vis[N][N];

bool dfs(int pos) {
    // pos >= 2
    if (a[pos - 1] == n) return true;
    if (pos > len) return false;
    memset(vis[pos], 0, sizeof vis[pos]);
    for (int i = pos - 1; i >= 1; --i) {
        if (a[i] + a[i] <= a[pos - 1]) break; // too small
        for (int j = i; j >= 1; --j) {
            int val = a[i] + a[j];
            if (val <= a[pos - 1]) break; // too small
            if (val > n || vis[pos][val]) continue;
            vis[pos][val] = true;
            a[pos] = val;
            if (dfs(pos + 1)) return true;
        }
    }
    return false;
}

int main() {
    while (scanf("%d", &n) != EOF && n) {
        if (n == 1) {
            puts("1");
            continue;
        }
        for (len = 1; len <= 20; ++len) {
            a[1] = 1;
            if (dfs(2)) break;
        }
        for (int i = 1; i <= len; ++i) printf("%d%c", a[i], " \n"[i == len]);
    }
    return 0;
}
