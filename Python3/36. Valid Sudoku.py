class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def iVS(b):
            d = set()
            for b1 in b:
                if b1 == '.':
                    continue
                if b1 in d:
                    return False
                d.add(b1)
            return True

        for row in board:
            if not iVS(row):
                return False
        for i in range(9):
            if not iVS([r[i] for r in board]):
                return False
        for i in range(3):
            if not iVS([board[3*i][0], board[3*i][1], board[3*i][2],
                        board[3*i+1][0], board[3*i+1][1], board[3*i+1][2],
                        board[3*i+2][0], board[3*i+2][1], board[3*i+2][2]]):
                return False
            if not iVS([board[3*i][3], board[3*i][4], board[3*i][5],
                        board[3*i+1][3], board[3*i+1][4], board[3*i+1][5],
                        board[3*i+2][3], board[3*i+2][4], board[3*i+2][5]]):
                return False
            if not iVS([board[3*i][6], board[3*i][7], board[3*i][8],
                        board[3*i+1][6], board[3*i+1][7], board[3*i+1][8],
                        board[3*i+2][6], board[3*i+2][7], board[3*i+2][8]]):
                return False
        return True
