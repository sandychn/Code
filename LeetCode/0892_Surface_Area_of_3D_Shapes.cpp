// Time  : 16 ms
// Memory: 8.9 MB

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        const int row = grid.size();
        const int col = grid[0].size();
        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    result += 2;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && y >= 0 && x < row && y < col) {
                            result += max(0, grid[i][j] - grid[x][y]);
                        } else {
                            result += grid[i][j];
                        }
                    }
                }
            }
        }
        return result;
    }
};
