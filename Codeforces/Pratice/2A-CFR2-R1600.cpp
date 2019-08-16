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

int main() {
    map<string, int> score;
    vector<tuple<string, int, int>> history;  // second: score, third: timeline
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string name;
        int delta;
        cin >> name >> delta;
        score[name] += delta;
        history.emplace_back(name, score[name], i);
    }
    int m = -1;
    for (auto valPair : score) {
        m = max(m, valPair.second);
        history.emplace_back(valPair.first, 0, 0);
    }
    set<string> candidates;
    for (auto valPair : score) {
        if (valPair.second == m) candidates.emplace(valPair.first);
    }
    int ans = INF;
    string winner;
    for (auto p : history) {
        string &name = get<0>(p);
        int sc = get<1>(p), time = get<2>(p);
        if (!candidates.count(name)) continue;
        if (sc >= m && time < ans) {
            ans = time;
            winner = name;
        }
    }
    cout << winner;
    return 0;
}
