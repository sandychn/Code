#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (int)(a); --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int N = 1050;
const int INF = 0x3F3F3F3F;

PII points[N];
vector<PII> edge[N];
int dist[N];

int main() {
    // freopen("2_2.in", "r", stdin);
    // freopen("22.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int y0, n, d;
        cin >> y0 >> n >> d;
        if (n == 0) {
            if (y0 <= d) cout << "YES\n1\n";
            else cout << "NO\n" << y0 << "\n";
            continue;
        }
        int t = n;
        rep(i, 0, n + 1) {
            edge[i].clear();
            dist[i] = INF;
        }
        rep(i, 0, n) {
            cin >> points[i].fi >> points[i].se;
        }
        rep(i, 0, n) {
            rep(j, i + 1, n) {
                int dx = points[i].fi - points[j].fi;
                int dy = points[i].se - points[j].se;
                int dist = dx * dx + dy * dy;
                if (dist <= d * d) {
                    edge[i].pb(mp(j, 1));
                    edge[j].pb(mp(i, 1));
                }
            }
        }
        priority_queue<PII, vector<PII> > heap;
        rep(i, 0, n) {
            if (points[i].se <= d) {
                heap.push(mp(-1, i));
                dist[i] = 1;
            }
            if (points[i].se + d >= y0) {
                edge[i].pb(mp(t, 1));
            }
        }
        int maxY = 0; // all points that can be reached, max y value
        while (!heap.empty()) {
            PII now = heap.top();
            heap.pop();
            maxY = max(maxY, points[now.se].se);
            rep(i, 0, sz(edge[now.se])) {
                int to = edge[now.se][i].fi;
                int cost = edge[now.se][i].se;
                if (-now.fi + cost < dist[to]) {
                    dist[to] = -now.fi + cost;
                    heap.push(mp(-dist[to], to));
                }
            }
        }
        if (dist[t] != INF) {
            cout << "YES\n" << dist[t] << "\n";
        } else {
            cout << "NO\n" << y0 - maxY << "\n";
        }
    }
    return 0;
}