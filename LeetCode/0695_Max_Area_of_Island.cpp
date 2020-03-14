// Time  : 16 ms
// Memory: 23.9 MB

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};
        int res = 1;
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= grid.size() || yy >= grid[0].size()) {
                continue;
            }
            if (grid[xx][yy] == 1) res += dfs(grid, xx, yy);
        }
        return res;
    }
};
