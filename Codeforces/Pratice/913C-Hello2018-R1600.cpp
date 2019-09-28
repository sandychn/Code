#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 33;

LL cost[N];

int main() {
    LL n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int i = 1; i < n; ++i) {
        cost[i] = min(cost[i - 1] * 2, cost[i]);
    }
    for (int i = n; i < N; ++i) {
        cost[i] = cost[i - 1] * 2;
    }
    LL res = 2e18, now = 0;
    for (int i = N - 1; i >= 0; --i) {
        LL x = 1LL << i;
        res = min(res, now + (l + x - 1) / x * cost[i]);
        if (l >= x) {
            now += cost[i];
            l -= x;
        }
    }
    cout << res;
    return 0;
}