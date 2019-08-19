#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() {
        freopen("sample.in", "r", stdin);
        // freopen("out.out", "w", stdout);
    }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

const int INF = 0x3F3F3F3F;
const int N = 405;

vector<int> railway[N], road[N];
bool connect[N][N];
int dist1[N], dist2[N];
int n, m;

struct Node {
    int pos, cost;
    Node() {}
    Node(int _pos, int _cost) : pos(_pos), cost(_cost) {}
    bool operator<(const Node &b) const {
        return cost > b.cost;
    }
};

void bfs(vector<int> *g, int *dist) {
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int to : g[now]) {
            if (dist[to] > dist[now] + 1) {
                dist[to] = dist[now] + 1;
                q.push(to);
            }
        }
    }
    // for (int i = 1; i <= n; ++i) printf("dist[%d]=%d\n", i, dist[i]);
}

int solve(vector<int> *g, int *dist, int *other) {
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    priority_queue<Node> q;
    q.emplace(1, 0);
    dist[1] = 0;
    while (!q.empty()) {
        Node now = q.top();
        q.pop();
        if (now.pos == n) return now.cost;
        for (int to : g[now.pos]) {
            if (now.cost + 1 == other[to]) {
                if (now.cost + 2 < dist[to]) {
                    dist[to] = now.cost + 2;
                    q.emplace(to, now.cost + 2);
                }
            } else if (now.cost + 1 < dist[to]) {
                dist[to] = now.cost + 1;
                q.emplace(to, now.cost + 1);
            }
        }
    }
    return INF;  // cannot reach
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        railway[u].push_back(v), railway[v].push_back(u);
        connect[u][v] = connect[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (!connect[i][j]) {
                road[i].push_back(j);
            }
        }
    }
    bfs(railway, dist1);
    int ans1 = max(dist1[n], solve(road, dist2, dist1));
    bfs(road, dist1);
    int ans2 = max(dist1[n], solve(railway, dist2, dist1));
    int ans = min(ans1, ans2);
    // cout << ans1 << ' ' << ans2 << endl;
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
    return 0;
}