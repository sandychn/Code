/*
 * @Author: Sandy
 * @Date: 2019-07-16 17:12:11
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-16 19:35:05
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

const int N = 105;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool prohibit[N * N];
vector<int> g[N * N];
bool vis[N * N];
int link[N * N];
int n;

void addEdge(int u, int v) { g[u].push_back(v); }

bool match(int x) {
    for (size_t i = 0; i < g[x].size(); ++i) {
        int to = g[x][i];
        if (vis[to]) continue;
        vis[to] = 1;
        if (!link[to] || match(link[to])) {
            link[to] = x;
            return true;
        }
    }
    return false;
}

int maxMatch() {
    memset(link, 0, sizeof(link));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (prohibit[i * n + j]) continue;
            if ((i + j) & 1) continue;
            memset(vis, 0, sizeof(vis));
            ans += match(i * n + j);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> n >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        prohibit[x * n + y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (prohibit[i * n + j]) continue;
            for (int k = 0; k < 4; ++k) {
                int xx = i + dx[k], yy = j + dy[k];
                if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
                if (prohibit[xx * n + yy]) continue;
                addEdge(i * n + j, xx * n + yy);
            }
        }
    }
    cout << maxMatch() << endl;
    return 0;
}