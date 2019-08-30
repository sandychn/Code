/*
直接正向建图错误样例
6->3->1
5->4->2
正向建图输出 5,4,2,6,3,1 (正向字典序最小)
逆向建图输出 6,3,1,5,4,2 (反向字典序最大)

如果点a和点b有直接和间接的拓扑关系，那么a和b的先后顺序由拓扑排序确定
如果点a和点b没有直接和简接的拓扑关系，那么a和b的先后顺序由a和b所能到达的点的大小确定
所以逆向处理，优先选大，逆向输出
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

const int N = 30099;
vector<int> e[N];
int indeg[N], ans[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) e[i].clear(), indeg[i] = 0;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        e[v].push_back(u);
        indeg[u]++;
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int now = q.top();
        q.pop();
        ans[cnt++] = now;
        for (int to : e[now]) {
            if (--indeg[to] == 0) q.push(to);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}