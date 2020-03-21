// Time  : 76 ms
// Memory: 25.8 MB

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int fa[N * 2 + 5];
        for (int i = 0; i <= N * 2; i++) fa[i] = i;
        int ans = 0;
        for (size_t i = 0; i < A.size(); i++) {
            int pos = find(fa, A[i]);
            ans += pos - A[i];
            fa[pos] = fa[pos + 1];
        }
        return ans;
    }

    // Below is standard solution.

    // int minIncrementForUnique(vector<int>& A) {
    //     int cnt[N * 2 + 5] = {};
    //     for (size_t i = 0; i < A.size(); i++) ++cnt[A[i]];
    //     int taken = 0;
    //     int ans = 0;
    //     for (size_t i = 0; i <= N * 2; i++) {
    //         if (cnt[i] > 1) {
    //             taken += cnt[i] - 1;
    //             ans -= i * (cnt[i] - 1);
    //         } else if (taken && cnt[i] == 0) {
    //             --taken;
    //             ans += i;
    //         }
    //     }
    //     return ans;
    // }

private:
    int find(int* fa, int x) {
        int root = x;
        while (fa[root] != root) {
            root = fa[root];
        }
        while (fa[x] != root) {
            int t = fa[x];
            fa[x] = root;
            x = t;
        }
        return root;
    }

    static const int N = 40000;
};
