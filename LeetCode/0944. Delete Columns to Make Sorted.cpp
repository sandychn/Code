// Time  : 52 ms (55.05%)
// Memory: 13 MB (49.79%)

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() <= 1) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < A[0].length(); i++) {
            for (int j = 1; j < A.size(); j++) {
                if (A[j - 1][i] > A[j][i]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
