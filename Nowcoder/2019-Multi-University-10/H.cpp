#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

// n-hexane {1: 2, 2: 4}
// 2-methylpentane {1: 3, 2: 2, 3: 1}
// 3-methylpentane {1: 3, 2: 2, 3: 1}
// 2,3-dimethylbutane {1: 4, 2: 0, 3: 2}
// 2,2-dimethylbutane {1: 4, 2: 1, 3: 0, 4: 1}

const int N = 10;

int deg[N], cnt[N];
vector<int> g[N];
bool vis[N];
int ans;

void dfs(int u, int cnt) {
    ans = max(ans, cnt);
    for (int v : g[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            dfs(v, cnt + 1);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 6; ++i) {
            deg[i] = 0;
            g[i].clear();
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= 5; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++, deg[v]++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= 6; ++i) {
            ++cnt[deg[i]];
        }
        if (cnt[1] == 2 && cnt[2] == 4) {
            puts("n-hexane");
        } else if (cnt[1] == 4 && cnt[3] == 2) {
            puts("2,3-dimethylbutane");
        } else if (cnt[1] == 4 && cnt[2] == 1 && cnt[4] == 1) {
            puts("2,2-dimethylbutane");
        } else {
            for (int i = 1; i <= 6; ++i) {
                if (deg[i] == 3) {
                    ans = 0;
                    memset(vis, 0, sizeof(vis));
                    vis[i] = 1;
                    dfs(i, 0);
                    // printf("%d\n", ans);
                    if (ans == 3) {
                        puts("2-methylpentane");
                    } else {
                        puts("3-methylpentane");
                    }
                    break;
                }
            }
        }
    }
    return 0;
}