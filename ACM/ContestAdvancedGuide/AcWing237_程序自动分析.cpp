// 2019-02-22
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int MAXN = 2e6 + 5;

struct DisjointSet {
    int fa[MAXN], sz[MAXN];
    void init(int n) {
        for(int i = 1; i <= n; ++i) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        int temp = x;
        while(fa[x] != x)
            x = fa[x];
        int rt = x, t;
        while(fa[temp] != rt) {
            t = fa[temp];
            fa[temp] = rt;
            temp = t;
        }
        return rt;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(same(x, y))
            return;
        if(sz[x] > sz[y]) {
            fa[y] = x;
            sz[x] += sz[y];
        } else {
            fa[x] = y;
            sz[y] += sz[x];
        }
    }
} DJS;

unordered_map<int, int> mp; // use unordered_map to mapping instead of sort(), unique() and lower_bound().
pair<int, int> equals[MAXN], unequals[MAXN];

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        int tot = 0, cnt1 = 0, cnt2 = 0;
        mp.clear();
        scanf("%d", &n);
        for(int i = 1, p, q, r; i <= n; ++i) {
            scanf("%d%d%d", &p, &q, &r);
            if(r == 1) equals[++cnt1] = {p, q};
            else unequals[++cnt2] = {p, q};
            if(!mp.count(p)) mp.emplace(p, ++tot);
            if(!mp.count(q)) mp.emplace(q, ++tot);
        }
        DJS.init(mp.size());
        for(int i = 1; i <= cnt1; ++i) {
            DJS.merge(mp[equals[i].first], mp[equals[i].second]);
        }
        bool flag = true;
        for(int i = 1; i <= cnt2; ++i) {
            if(DJS.same(mp[unequals[i].first], mp[unequals[i].second])) {
                flag = false;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
