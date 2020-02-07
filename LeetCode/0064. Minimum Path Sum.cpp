// Time  : 8 ms (90.00%)
// Memory: 10.6 MB (50.22%)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid[0].size();
        const int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                int result = INT_MAX;
                if (i) result = min(grid[i - 1][j] + grid[i][j], result);
                if (j) result = min(grid[i][j - 1] + grid[i][j], result);
                grid[i][j] = result;
            }
        }
        return grid[n - 1][m - 1];
    }
};
