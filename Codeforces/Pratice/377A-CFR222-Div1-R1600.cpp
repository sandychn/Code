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

const int INF = 0x3F3F3F3F;
const LL INF_LL = 0x3F3F3F3F3F3F3F3FLL;
const int N = 505;
const int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char s[N][N];
bool vis[N][N];
int n, m, k;

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4 && k; ++i) {
        int xx = x + go[i][0], yy = y + go[i][1];
        if (!vis[xx][yy] && s[xx][yy] == '.') dfs(xx, yy);
    }
    if (k) {
        s[x][y] = 'X';
        --k;
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> (s[i] + 1);
    for (int i = 1; i <= n && k; ++i) {
        for (int j = 1; j <= m && k; ++j) {
            if (s[i][j] == '.') dfs(i, j);
        }
    }
    for (int i = 1; i <= n; ++i) cout << (s[i] + 1) << endl;    
    return 0;
}