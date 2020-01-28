#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e5+10;

int color[N], cnt[2], cnt2[2], deg[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        cnt[color[i]]++;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (color[u] == color[v]) {
            continue;
        }
        deg[u]++;
        deg[v]++;
        if(!vis[u]) cnt2[color[u]] ++;
        if(!vis[v]) cnt2[color[v]] ++;
        vis[u] = vis[v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        if(deg[i]) cout << cnt[color[i]] - 1 + deg[i] + (cnt[color[i] ^ 1] - deg[i]) * 2;
        else cout << cnt[color[i]] - 1 + cnt2[color[i]^1] * 2 + (cnt[color[i]^1] - cnt2[color[i]^1]) * 3;
    }
    cout << endl;
    return 0;
}