#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x)                                                     \
    cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" \
         << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() {
        cerr << "\nTime: " << int(1000.0 * clock() / CLOCKS_PER_SEC) << " ms\n";
    }
} _tester;
#else
#define show(x)
#endif

const int N = 30;
const int M = 1050;

int deg[N];  // out+1, in-1
bool vis[N];
int fa[N], cnt;
char s[M];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        ++cnt;
        fa[x] = y;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        memset(deg, 0, sizeof(deg));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= 26; ++i) fa[i] = i;
        cnt = 0;
        while (n--) {
            scanf("%s", s);
            int len = strlen(s);
            int first = s[0] - 'a' + 1;
            int last = s[len - 1] - 'a' + 1;
            --deg[first], ++deg[last];
            vis[first] = vis[last] = 1;
            join(first, last);
        }
        int one = 0, negOne = 0, zero = 0, all = 0;
        for (int i = 1; i <= 26; ++i) {
            if (!vis[i]) continue;
            ++all;
            if (deg[i] == 0) ++zero;
            else if (deg[i] == 1) ++one;
            else if (deg[i] == -1) ++negOne;
        }
        if (cnt == all - 1 && (all == zero || (one == 1 && negOne == 1 && zero == all - 2))) {
            puts("Ordering is possible.");
        } else {
            puts("The door cannot be opened.");
        }
    }
    return 0;
}