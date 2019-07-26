// 2019-02-10
#include <stdio.h>
#include <deque>

using namespace std;

inline int getId(char x) {
    if (x == '0') return 10;
    if (x <= '9') return x - '0';
    if (x == 'A') return 1;
    if (x == 'J') return 11;
    if (x == 'Q') return 12;
    return 13;
}

deque<pair<int, bool> > q[15];

int main() {
    for (int i = 1; i <= 13; ++i) {
        for (int j = 1; j <= 4; ++j) {
            char x; scanf("%c%*c", &x);
            q[i].emplace_back(getId(x), false);
        }
    }
    int hp = 4, step = 1;
    pair<int, bool> now;
    while (hp) {
        if (step == 1) {
            now = q[13].front();
            q[13].pop_front();
            step = 2;
        } else if (step == 2) {
            if (now.first == 13) {
                --hp;
                step = 1;
                continue;
            }
            int pos = now.first;
            q[pos].emplace_front(now.first, true);
            now = q[pos].back();
            q[pos].pop_back();
        }
    }
    int ans = 0;
    for (int i = 1; i <= 13; ++i) {
        if (q[i].empty()) continue;
        int first = q[i].front().first;
        if (first == 13) continue;
        int cnt = 0;
        for (auto &x : q[i]) {
            if (!x.second) break;
            if (x.first == first) ++cnt;
            else break;
        }
        if (cnt == 4) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
