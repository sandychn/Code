/*
 * @Author: Sandy
 * @Date: 2019-07-28 15:09:23
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-28 20:48:32
 */

// 线段树建笛卡尔树 O(NlogN)
// POJ-2201 题目直接建笛卡尔树, 输出笛卡尔树每个结点的双亲/左子树/右子树

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 50050;

struct Input {
    int id, pos, key; // pos 是二叉搜索树权值, key 是小根堆权值
    bool operator<(const Input &b) const {
        return pos < b.pos;
    }
} input[N];

int id[N];

struct SegmentTree {
    struct Node {
        int minPos;
    } tree[N * 4];

    void pushUp(int rt) {
        if (input[tree[rt << 1].minPos].key < input[tree[rt << 1 | 1].minPos].key) {
            tree[rt].minPos = tree[rt << 1].minPos;
        } else {
            tree[rt].minPos = tree[rt << 1 | 1].minPos;
        }
    }

    void build(int l, int r, int rt = 1) {
        if (l == r) {
            tree[rt].minPos = l;  // 存最小值所在位置下标
        } else {
            int mid = (l + r) >> 1;
            build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
            pushUp(rt);
        }
    }

    int query(int l, int r, int L, int R, int rt = 1) {  // 返回最小值所在位置下标
        if (l == L && r == R) return tree[rt].minPos;
        int mid = (L + R) >> 1;
        if (r <= mid) return query(l, r, L, mid, rt << 1);
        if (l > mid) return query(l, r, mid + 1, R, rt << 1 | 1);
        int leftResult = query(l, mid, L, mid, rt << 1);
        int rightResult = query(mid + 1, r, mid + 1, R, rt << 1 | 1);
        return input[leftResult].key < input[rightResult].key ? leftResult : rightResult;
    }
};

struct CartesianTree {
    struct Node {
        int fa, ls, rs;
    } node[N];
    SegmentTree segTree;

    int size;
    void setSize(int n) { size = n; }

    int build() { // 返回笛卡尔树树根在node数组中下标
        segTree.build(1, size);
        return _build(1, size);
    }

    int _build(int l, int r) {
        if (l > r) return 0;
        int pos = segTree.query(l, r, 1, size);
        node[pos].ls = _build(l, pos - 1);
        if (node[pos].ls) node[node[pos].ls].fa = pos;
        node[pos].rs = _build(pos + 1, r);
        if (node[pos].rs) node[node[pos].rs].fa = pos;
        return pos;
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