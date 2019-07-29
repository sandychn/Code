/*
 * @Author: Sandy
 * @Date: 2019-07-28 20:50:00
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-28 21:02:22
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

typedef long long LL;

const int N = 100050;

int key[N];  //  小根堆权值

struct CartesianTree {
    struct Node {
        int fa, ls, rs;
    } node[N];
    int size, root;

    void init(int size) {
        this->size = size;
        root = 0;
    }

    void build() {
        stack<int> st;
        for (int i = 1; i <= size; ++i) {
            node[i].fa = node[i].ls = node[i].rs = 0;
            int j = 0;
            while (!st.empty() && key[st.top()] > key[i]) {
                j = st.top();
                st.pop();
            }
            if (st.empty()) {
                root = i;
            } else {
                node[st.top()].rs = i;
                node[i].fa = st.top();
            }
            node[i].ls = j;
            node[j].fa = i;
            st.push(i);
        }
    }
} tree;

int lSize[N], rSize[N];

int dfs(int root) {
    if (!root) return 0;
    int ls = tree.node[root].ls, rs = tree.node[root].rs;
    return (lSize[root] = dfs(ls)) + (rSize[root] = dfs(rs)) + 1;
}

int main() {
#ifdef _LOCAL
    freopen("test.in", "r", stdin);
#endif

    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", key + i);
        tree.init(n);
        tree.build();
        dfs(tree.root);
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, 1LL * key[i] * (lSize[i] + rSize[i] + 1));
        }
        printf("%I64d\n", ans);
    }

#ifdef _LOCAL
    fprintf(stderr, "Time elapsed: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC));
#endif
    return 0;
}