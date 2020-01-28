#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

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

const int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int N = 25;

vector<LL> vals[N];
int ans[N];

void dfs(int stick, bool first, const int id, LL val) {
    if (stick == 0) {
        vals[id].push_back(val);
        return;
    }
    for (int i = first ? 1 : 0; i < 10; ++i) {
        if (stick >= cost[i]) {
            dfs(stick - cost[i], false, id, val * 10 + i);
        }
    }
}

int getCost(LL val) {
    if (val == 0) {
        return cost[0];
    }
    int sum = 0;
    while (val) {
        sum += cost[val % 10];
        val /= 10;
    }
    return sum;
}

int main() {
    vals[cost[0]].push_back(0);
    for (int i = 2; i < N; ++i) {
        dfs(i, true, i, 0);
    }
    for (int cost1 = 2; cost1 < N; ++cost1) {
        for (int cost2 = 2; cost1 + cost2 + 4 < N; ++cost2) {
            for (int i = 0; i < (int)vals[cost1].size(); ++i) {
                for (int j = 0; j < (int)vals[cost2].size(); ++j) {
                    int val3 = vals[cost1][i] + vals[cost2][j];
                    int cost3 = getCost(val3);
                    int cost = cost1 + cost2 + cost3 + 4;
                    if (cost < N) {
                        ++ans[cost];
                    }
                }
            }
        }
    }
    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }
    return 0;
}
