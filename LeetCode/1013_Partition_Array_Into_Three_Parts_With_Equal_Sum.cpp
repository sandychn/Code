// Time  : 48 ms
// Memory: 33.2 MB

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        const int n = A.size();
        const int total = accumulate(A.begin(), A.end(), 0);
        if (total % 3 != 0) return false;

        vector<int> sum(n);
        sum[0] = A[0];

        bool flag = (sum[0] == total / 3);

        for (int i = 1; i < n - 1; i++) {
            sum[i] = sum[i - 1] + A[i];
            if (flag && sum[i] == total / 3 * 2) return true;
            if (sum[i] == total / 3) flag = true;
        }
        return false;
    }
};
