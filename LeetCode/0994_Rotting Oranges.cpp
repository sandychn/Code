// Time  : 4 ms
// Memory: 15.2 MB

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        const int rows = grid.size();
        const int cols = grid[0].size();

        int minutes = 0;
        int freshCount = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        while (!q.empty()) {
            bool flag = false;
            for (int size = q.size(); size--; ) {
                auto pos = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    if (pos.first + dx[i] < 0 || pos.first + dx[i] >= rows) continue;
                    if (pos.second + dy[i] < 0 || pos.second + dy[i] >= cols) continue;
                    if (grid[pos.first + dx[i]][pos.second + dy[i]] == 1) {
                        grid[pos.first + dx[i]][pos.second + dy[i]] = 2;
                        --freshCount;
                        flag = true;
                        q.emplace(pos.first + dx[i], pos.second + dy[i]);
                    }
                }
            }
            if (flag) minutes++;
        }

        return freshCount ? -1 : minutes;
    }
};
