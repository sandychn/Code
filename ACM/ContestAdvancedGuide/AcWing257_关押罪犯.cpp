/*
 * @Author: Sandy
 * @Date: 2019-07-16 16:23:22
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-16 16:23:44
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20050;
const int MAXM = 100050;

struct Node {
    int u, v, w;
} a[MAXM];

vector<int> edge[MAXN];
int v[MAXN];

bool dfs(int x, int color) {
    v[x] = color;
    for (size_t i = 0; i < edge[x].size(); ++i) {
        int y = edge[x][i];
        if (v[y] == 0) {
            if (!dfs(y, 3 - color)) return false;
        } else if (v[y] == color) {
            return false;
        }
    }
    return true;
}

bool isBipartiteGraph(int n) {
    for (int i = 1; i <= n; ++i) v[i] = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == 0 && !dfs(i, 1)) {
            return false;
        }
    }
    return true;
}

void addEdge(int u, int v) { edge[u].push_back(v); }

void makeGraph(int n, int m, int mid) {
    // make the graph from scratch
    for (int i = 1; i <= n; ++i) edge[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if (w >= mid) {
            addEdge(u, v);
            addEdge(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    int l = 0, r = 1e9 + 10;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        makeGraph(n, m, mid);
        if (isBipartiteGraph(n)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << '\n';
    return 0;
}
