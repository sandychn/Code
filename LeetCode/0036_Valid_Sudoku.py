class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        N = 9
        for i in range(N):
            visited = 0
            for j in range(N):
                if board[i][j] == '.':
                    continue
                if (visited >> int(board[i][j])) & 1:
                    return False
                visited |= 1 << int(board[i][j])
        for j in range(N):
            visited = 0
            for i in range(N):
                if board[i][j] == '.':
                    continue
                if (visited >> int(board[i][j])) & 1:
                    return False
                visited |= 1 << int(board[i][j])
        for i in range(N):
            visited = 0
            for x in range(i // 3 * 3, i // 3 * 3 + 3):
                for y in range(i % 3 * 3, i % 3 * 3 + 3):
                    if board[x][y] == '.':
                        continue
                    if (visited >> int(board[x][y])) & 1:
                        return False
                    visited |= 1 << int(board[x][y])
        return True
