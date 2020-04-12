class Solution:
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        ans = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X':
                    if (i == 0 and j == 0) or \
                            (i == 0 and board[i][j - 1] != 'X') or \
                            (j == 0 and board[i - 1][j] != 'X') or \
                            (board[i - 1][j] != 'X' and board[i][j - 1] != 'X'):
                        ans += 1
        return ans


sol = Solution()
print(sol.countBattleships([["X", ".", ".", "X"],
                            [".", ".", ".", "X"],
                            [".", ".", ".", "X"]]))
