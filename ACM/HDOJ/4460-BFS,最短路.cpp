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

const int N = 1050;

unordered_map<string, int> mp;
vector<pair<int, int>> e[N];
int fa[N], siz;
bool inq[N];
int dist[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i;
    siz = n;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    fa[a] = b, --siz;
}

int spfa(int n, int s) { // s是起点
    for (int i = 1; i <= n; ++i) dist[i] = INF, inq[i] = false;
    queue<int> q;
    dist[s] = 0, inq[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < (int)e[u].size(); ++i) {
            int v = e[u][i].first, w = e[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dist[i]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    string s, t;
    while (cin >> n && n) {
        mp.clear();
        for (int i = 1; i <= n; ++i) e[i].clear();
        init(n);
        for (int cnt = 1; cnt <= n; ++cnt) {
            cin >> s;
            mp[s] = cnt;
        }
        cin >> m;
        while (m--) {
            cin >> s >> t;
            int u = mp[s], v = mp[t];
            join(u, v);
            e[u].emplace_back(v, 1);
            e[v].emplace_back(u, 1);
        }
        if (siz != 1) {
            cout << "-1\n";
        } else {
            int ans = 0;
            for (int i = 1; i <= n; ++i) ans = max(ans, spfa(n, i));
            cout << ans << endl;
        }
    }
    return 0;
}