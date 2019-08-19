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

const int N = 55;
// const int INF = 0x3F3F3F3F;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;

char from[N][N];
char to[N][N];

list<int> ans[N];
bool vis[N];
int res[N];
int n, m;

// int link[55];
// bool vvis[55];

// bool dfs(int pos) {
//     for (auto rit = ans[pos].rbegin(); rit != ans[pos].rend(); ++rit) {
//         int to = *rit;
//         if (!vvis[to]) {
//             vvis[to] = 1;
//             if (link[to] == 0 || dfs(link[to])) {
//                 link[to] = pos;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int getAns() {
//     int ans = 0;
//     memset(link, 0, sizeof(link));
//     for (int i = 1; i <= m; ++i) {
//         memset(vvis, 0, sizeof(vvis));
//         if (dfs(i)) ++ans;
//     }
//     return ans;
// }

bool solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch = from[i][j];
            for (list<int>::iterator it = ans[j].begin(); it != ans[j].end();) {
                int pos = *it;
                if (to[i][pos] != ch) {
                    ans[j].erase(it++);
                    // printf("i=%d j=%d pos=%d not ok (ch=%c, to[i][pos]=%c)\n", i, j, pos, ch, to[i][pos]);
                } else {
                    ++it;
                }
            }
            if (ans[j].empty()) return false;
        }
    }
    // int match = getAns();
    // if (match != m) return false;
    // for (int i = 1; i <= m; ++i) {
    //     res[link[i]] = i;
    // }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; ++i) {
        while (!ans[i].empty() && vis[ans[i].front()]) ans[i].pop_front();
        if (ans[i].empty()) {
            return false;
        }
        vis[ans[i].front()] = true;
        res[i] = ans[i].front();
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d%c", res[i], " \n"[i == m]);
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%s%s", from[i] + 1, to[i] + 1);
        for (int i = 1; i <= m; ++i) {
            ans[i].clear();
            for (int j = 1; j <= m; ++j) {
                ans[i].push_back(j);
            }
        }
        if (!solve()) puts("-1");
    }
    return 0;
}