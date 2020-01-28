/*
 * @Author: Sandy
 * @Date: 2019-07-28 15:09:23
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-28 20:48:26
 */

// 单调栈建笛卡尔树 O(N)
// POJ-2201 题目直接建笛卡尔树, 输出笛卡尔树每个结点的双亲/左子树/右子树

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

const int N = 50050;

struct Input {
    int id, pos, key; // pos 是二叉搜索树权值, key 是小根堆权值
    bool operator<(const Input &b) const {
        return pos < b.pos;
    }
} input[N];

int id[N];

struct CartesianTree {
    struct Node {
        int fa, ls, rs;
    } node[N];

    int size;
    void setSize(int n) { size = n; }

    void build() {
        int root;
        stack<int> st;
        for (int i = 1; i <= size; ++i) {
            node[i].fa = node[i].ls = node[i].rs = 0;
            int j = 0;
            while (!st.empty() && input[st.top()].key > input[i].key) {
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

int main() {
#ifdef _LOCAL
    freopen("test.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &input[i].pos, &input[i].key);
        input[i].id = i;
    }
    sort(input + 1, input + n + 1);

    tree.setSize(n);
    tree.build();

    for (int i = 1; i <= n; ++i) id[input[i].id] = i;

    puts("YES");
    for (int i = 1; i <= n; ++i) {
        int indexInSortedInput = id[i];
        const CartesianTree::Node &node = tree.node[indexInSortedInput];
        printf("%d %d %d\n", input[node.fa].id, input[node.ls].id, input[node.rs].id);
    }

#ifdef _LOCAL
    fprintf(stderr, "Time elapsed: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC));
#endif
    return 0;
}