#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rows = board.size(), cols = board[0].size();
        for (int i=0; i < rows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, cols-1);
        }
        for (int i=0; i < cols; ++i) {
            dfs(board, 0, i);
            dfs(board, rows-1, i);
        }
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '.') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size(), cols = board[0].size();
        if (r >= rows || r < 0 || c >= cols || c < 0) return;
        if (board[r][c] != 'O') return;
        board[r][c] = '.';
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r, c-1);
        dfs(board, r, c+1);
    }
};

int main() {
    vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    for (int i=0; i < board.size(); ++i) {
        for (int j=0; j < board[i].size(); ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    Solution sol;
    sol.solve(board);
    for (int i=0; i < board.size(); ++i) {
        for (int j=0; j < board[i].size(); ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
