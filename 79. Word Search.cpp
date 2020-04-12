#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0; i < board.size(); ++i) {
            for (int j=0; j < board[0].size(); ++j) {
                if (backtracking(board, isVisited, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board,vector<vector<bool>>& isVisited, string& word, int p, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if (isVisited[r][c] || board[r][c] != word[p]) return false;
        if (p == word.size()-1) return true;
        isVisited[r][c] = true;
        if (backtracking(board, isVisited, word, p+1, r-1, c)) return true;
        if (backtracking(board, isVisited, word, p+1, r+1, c)) return true;
        if (backtracking(board, isVisited, word, p+1, r, c-1)) return true;
        if (backtracking(board, isVisited, word, p+1, r, c+1)) return true;
        isVisited[r][c] = false;
        return false;
    }
};

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
    cout << (a.exist(sudoku, "..........")?"true":"false") << endl;
    return 0;
}
