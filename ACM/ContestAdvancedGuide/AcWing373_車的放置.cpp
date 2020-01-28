/*
 * @Author: Sandy 
 * @Date: 2019-07-17 15:01:02 
 * @Last Modified by:   Sandy 
 * @Last Modified time: 2019-07-17 15:01:02 
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 205;

bool prohibit[N][N];
vector<int> g[N];
bool vis[N];
int link[N];

bool match(int x) {
    for (size_t i = 0; i < g[x].size(); ++i) {
        int to = g[x][i];
        if (!vis[to]) {
            vis[to] = 1;
            if (link[to] == 0 || match(link[to])) {
                link[to] = x;
                return true;
            }
        }
    }
    return false;
}

int maxMatch(int n) {
    memset(link, 0, sizeof(link));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        ans += match(i);
    }
    return ans;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        prohibit[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!prohibit[i][j]) {
                g[i].push_back(j);
                // g[j + n].push_back(i);
            }
        }
    }
    cout << maxMatch(n) << endl;
    return 0;
}