#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // blocks_index = (r / 3) * 3 + (col / 3);
        // 9r 9c 9b
        // 找到已填好最多的一个值（且没有填满）
        // 填入一个值
        // 递归
        // 修改填入的值
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> blocks(9, 0);
        int now = 0;
        for (int i=0; i < 9; ++i) {
            for (int j=0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    ++rows[i];
                    ++cols[j];
                    ++blocks[(i/3)*3+(j/3)];
                    ++now;
                }
            }
        }
        backtracking(board, rows, cols, blocks, now);
    }

    bool backtracking(vector<vector<char>>& board, vector<int> &rows, vector<int> &cols, vector<int> &blocks, int now) {
        if (now == 9 * 9) return true;
        int r_max = 0, c_max = 0, b_max = 0;
        // 找填的最满的部分
        for (int i=1; i < 9; ++i) {
            if (rows[r_max] == 9 || rows[i] != 9 && rows[i] > rows[r_max]) r_max = i;
            if (cols[c_max] == 9 || cols[i] != 9 && cols[i] > cols[c_max]) c_max = i;
            if (blocks[b_max] == 9 || blocks[i] != 9 && blocks[i] > blocks[b_max]) b_max = i;
        }
        // 找空格位置以及可填的值
        if (rows[r_max] >= cols[c_max] && rows[r_max] >= blocks[b_max]) {
            int r = r_max;
            for (int c=0; c < 9; ++c) {
                if (board[r][c] == '.') {  // 空格
                    for (int num=1; num <= 9; ++num) {
                        if (canWriteIn(board, r, c, num)) {
                            board[r][c] = '0' + num;
                            ++rows[r];
                            ++cols[c];
                            ++blocks[(r / 3) * 3 + (c / 3)];
                            if (backtracking(board, rows, cols, blocks, now+1)) return true;
                            board[r][c] = '.';
                            --rows[r];
                            --cols[c];
                            --blocks[(r / 3) * 3 + (c / 3)];
                        }
                    }
                    return false;
                }
            }
        }
        else if (cols[c_max] >= rows[r_max] && cols[c_max] >= blocks[b_max]) {
            int c = c_max;
            for (int r=0; r < 9; ++r) {
                if (board[r][c] == '.') {  // 空格
                    for (int num=1; num <= 9; ++num) {
                        if (canWriteIn(board, r, c, num)) {
                            board[r][c] = '0' + num;
                            ++rows[r];
                            ++cols[c];
                            ++blocks[(r / 3) * 3 + (c / 3)];
                            if (backtracking(board, rows, cols, blocks, now+1)) return true;
                            board[r][c] = '.';
                            --rows[r];
                            --cols[c];
                            --blocks[(r / 3) * 3 + (c / 3)];
                        }
                    }
                    return false;
                }
            }
        }
        else if (blocks[b_max] >= rows[r_max] && blocks[b_max] >= cols[c_max]) {
            int rr = 3*(b_max / 3), cc = 3*(b_max % 3);
            for (int ii = 0; ii < 3; ++ii) {
                for (int jj=0; jj < 3; ++jj) {
                    int r = rr + ii;
                    int c = cc + jj;
                    if (board[r][c] == '.') {  // 空格
                        for (int num=1; num <= 9; ++num) {
                            if (canWriteIn(board, r, c, num)) {
                                board[r][c] = '0' + num;
                                ++rows[r];
                                ++cols[c];
                                ++blocks[(r / 3) * 3 + (c / 3)];
                                if (backtracking(board, rows, cols, blocks, now+1)) return true;
                                board[r][c] = '.';
                                --rows[r];
                                --cols[c];
                                --blocks[(r / 3) * 3 + (c / 3)];
                            }
                        }
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool canWriteIn(vector<vector<char>>& board, int r, int c, int num) {
        for (int i=0; i < 9; ++i) {
            if (board[r][i] - '0' == num) return false;
            if (board[i][c] - '0' == num) return false;
        }
        int block_index = (r / 3) * 3 + (c / 3);
        int rr = 3*(block_index / 3), cc = 3*(block_index % 3);
        for (int i=0; i < 3; ++i) {
            for (int j=0; j < 3; ++j) {
                if (board[rr+i][cc+j] - '0' == num) return false;
            }
        }
        return true;
    }
};


// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

int main() {
    Solution a;
    vector<vector<char>> sudoku{vector<char>{'5','3','.','.','7','.','.','.','.'},vector<char>{'6','.','.','1','9','5','.','.','.'},vector<char>{'.','9','8','.','.','.','.','6','.'},vector<char>{'8','.','.','.','6','.','.','.','3'},vector<char>{'4','.','.','8','.','3','.','.','1'},vector<char>{'7','.','.','.','2','.','.','.','6'},vector<char>{'.','6','.','.','.','.','2','8','.'},vector<char>{'.','.','.','4','1','9','.','.','5'},vector<char>{'.','.','.','.','8','.','.','7','9'}};
    for (int i=0; i < 9; ++i) {
        for (int j=0; j < 9; ++j) {
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    cout << endl;
    a.solveSudoku(sudoku);
    for (int i=0; i < 9; ++i) {
        for (int j=0; j < 9; ++j) {
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    return 0;
}
