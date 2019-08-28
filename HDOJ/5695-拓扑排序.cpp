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

const int N = 1e5 + 99;
vector<int> e[N];
int indeg[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        indeg[i] = 0;
    }
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        indeg[v]++;
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }
    int Min = INF;
    LL res = 0;
    while (!q.empty()) {
        int now = q.top();
        q.pop();
        Min = min(Min, now);
        res += Min;
        for (int to : e[now]) {
            if (--indeg[to] == 0) q.push(to);
        }
    }
    cout << res << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
