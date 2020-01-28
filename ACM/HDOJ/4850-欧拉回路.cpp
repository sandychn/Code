#include <bits/stdc++.h>

using namespace std;

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

const int N = 26;

char ans[N * N * N * N + 30];
int top;
int cnt[N * N * N + 5];

stack<int> stk;

void extend(int pos) {
    while (cnt[pos] < N) {
        int to = pos * N + cnt[pos];
        ++cnt[pos];
        stk.push(to);
        pos = to % (N * N * N);
        cout << pos << endl;
    }
}

void solve() {
    extend(0);
    while (!stk.empty()) {
        int now = stk.top();
        stk.pop();
        extend(now / N);
        ans[++top] = now % N + 'a';
    }
    for (int i = 1; i <= 3; ++i) ans[++top] = 'a';
}

int main() {
    solve();
    int n;
    while (~scanf("%d", &n)) {
        puts(n > top ? "Impossible" : ans + top - n + 1);
    }
    return 0;
}