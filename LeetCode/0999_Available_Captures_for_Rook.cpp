// Time  : 4 ms
// Memory: 6.2 MB

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        int rookx, rooky;
        
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'R') {
                    rookx = i;
                    rooky = j;
                    break;
                }
        
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int step = 1, x, y;
                 (x = rookx + dx[i] * step) >= 0 && x < 8 && (y = rooky + dy[i] * step) >= 0 && y < 8;
                 step++) {
                if (board[x][y] == 'p') {
                    ++ans;
                    break;
                }
                if (board[x][y] == 'B') break;
            }
        }
        
        return ans;
    }
};
