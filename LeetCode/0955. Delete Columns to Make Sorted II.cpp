// Time  : 4 ms (100.00%)
// Memory: 9.6 MB (36.95%)


class Solution {
   public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty()) {
            return 0;
        }
        int len = A[0].size();
        int ans = 0;
        bool *cut = new bool[A.size()]();
        for (int i = 0; i < len; i++) {
            bool flag = false;
            for (int j = 0; j < (int)A.size() - 1; j++) {
                if (!cut[j] && A[j][i] > A[j + 1][i]) { // column i should be deleted.
                    ++ans;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            // keep this column
            for (int j = 0; j < (int)A.size() - 1; j++) {
                if (A[j][i] < A[j + 1][i]) {
                    cut[j] = true;
                }
            }
        }
        return ans;
    }
};