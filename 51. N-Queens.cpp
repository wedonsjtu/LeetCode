#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n < 0) return ans;
        vector<bool> col(n, false), lud(2*n-1, false), rud(2*n-1, false);
        vector<string> board(n, string(n, '.'));
        backtracking(ans, board, col, lud, rud, 0, n);
        return ans;
    }

    void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<bool> &col, 
                      vector<bool> &lud, vector<bool> &rud, int r, int n) {
        if (r == n) {
            ans.push_back(board);
            return;
        }
        for (int c=0; c < n; ++c) {
            if (col[c] || lud[n-r+c-1] || rud[r+c]) continue;
            board[r][c] = 'Q';
            col[c] = lud[n-r+c-1] = rud[r+c] = true;
            backtracking(ans, board, col, lud, rud, r+1, n);
            col[c] = lud[n-r+c-1] = rud[r+c] = false;
            board[r][c] = '.';
        }
    }
};

int main() {
    Solution a;
    vector<vector<string>> boards = a.solveNQueens(12);
    if (false) {
        for (auto &board: boards) {
            for (string s: board) {
                cout << s << endl;
            }
            cout << endl;
        }
    }
    cout << "Size: " << boards.size() << endl;
    return 0;
}
