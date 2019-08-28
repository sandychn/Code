#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

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

const int N = 25;

vector<char> var;
vector<int> ans[N];
vector<int> e[N];
int indeg[N], n;
bool vis[N];

int getId(char ch) {
    return lower_bound(var.begin(), var.end(), ch) - var.begin() + 1;
}

void dfs(int cnt, string &str) {
    if (cnt == n) {
        cout << str << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || indeg[i]) continue;
        for (int j = 0; j < (int)e[i].size(); ++j) {
            int to = e[i][j];
            --indeg[to];
        }
        vis[i] = true;
        str.push_back(var[i - 1]);
        dfs(cnt + 1, str);
        vis[i] = false;
        str.erase(--str.end()); // pop_back() since C++11
        for (int j = 0; j < (int)e[i].size(); ++j) {
            int to = e[i][j];
            ++indeg[to];
        }
    }
}

int main() {
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        var.clear();
        for (int i = 0; i < N; ++i) {
            e[i].clear();
            ans[i].clear();
            indeg[i] = 0;
        }
        n = 0;
        for (int i = 0; i < (int)s.length(); i += 2, ++n) {
            var.push_back(s[i]);
        }
        sort(var.begin(), var.end());
        for (int i = 0; i < (int)t.length(); i += 4) {
            char p1 = t[i], p2 = t[i + 2];
            int id1 = getId(p1), id2 = getId(p2);
            e[id1].push_back(id2);
            ++indeg[id2];
        }
        string s;
        s.reserve(n);
        dfs(0, s);
        cout << '\n';
    }
    return 0;
}