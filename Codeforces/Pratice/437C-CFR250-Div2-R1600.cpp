#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("../sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

const int N = 1050;

vector<int> g[N];
int c[N];
bool del[N];
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        a[i].first = c[i];
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int pos = a[i].second;
        for (int to : g[pos]) {
            if (!del[to]) {
                ans += c[to];
            }
        }
        del[pos] = true;
    }
    cout << ans << endl;
    return 0;
}