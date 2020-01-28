/*
 * @Author: Sandy 
 * @Date: 2019-08-22 02:08:35 
 * @Last Modified by:   Sandy 
 * @Last Modified time: 2019-08-22 02:08:35 
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

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

const int N = 1e5 + 10;

LL sum[N];
int id[N], tree[N];
pair<LL, int> a[N];

#define lowbit(x) (x) & (-(x))

void add(int pos, int val, int n) {
    while (pos <= n) tree[pos] += val, pos += lowbit(pos);
}

int ask(int pos) {
    int ans = 0;
    while (pos) ans += tree[pos], pos -= lowbit(pos);
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1, x; i <= n; ++i) {
            scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
            a[i] = make_pair(sum[i], i);
        }
        a[0] = make_pair(0, 0);
        sort(a, a + n + 1);
        for (int i = 0; i <= n; ++i) id[a[i].second] = i + 1;
        memset(tree, 0, sizeof(tree));
        LL ans = 0;
        for (int right = 0; right <= n; ++right) {
            ans += ask(id[right]);
            add(id[right], 1, n + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

// -1 2 -2 5
// (-1, 2, -2, 5) = 4
// (2, -2, 5) = 5
// (-1, 2) = 1
// (2, -2) = 0
// (-2, 5) = 3
// (2) = 2
// (5) = 5