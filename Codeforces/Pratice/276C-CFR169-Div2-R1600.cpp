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
} _shower;
#else
#define show(x)
#endif

const int N = 2e5 + 10;

LL a[N];
int vis[N];
priority_queue<pair<int, int>> heap; // count, pos
priority_queue<int> nums;

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        nums.emplace(x);
    }
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        ++vis[l], --vis[r + 1];
    }
    for (int i = 1; i < N; ++i) {
        vis[i] += vis[i - 1];
        if (vis[i]) heap.emplace(vis[i], i);
    }
    LL ans = 0;
    while (!heap.empty()) {
        ans += (LL)nums.top() * heap.top().first;
        nums.pop(), heap.pop();
    }
    cout << ans << endl;
    return 0;
}