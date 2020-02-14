// Time  : 0 ms (100.00%)
// Memory: 8.8 MB (17.76%)

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for (int j = 0; j < n; j++) dp[j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < m; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];

        // vector<vector<int>> dp(m, vector<int>(n));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0)
        //             dp[i][j] = 1;
        //         else if (i == 0)
        //             dp[i][j] = dp[i][j - 1];
        //         else if (j == 0)
        //             dp[i][j] = dp[i - 1][j];
        //         else
        //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }
        // return dp[m - 1][n - 1];
    }
};
