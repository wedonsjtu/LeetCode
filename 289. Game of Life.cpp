#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rows = board.size(), cols = board[0].size();
        int other_live = 0, other_die = 0;  // other_die is unused
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                other_live = 0;
                other_die = 0;
                if (i > 0 && j > 0) {
                    if (board[i-1][j-1] >= 1) ++other_live;
                    else if (board[i-1][j-1] <= 0) ++other_die;
                }
                if (i > 0) {
                    if (board[i-1][j] >= 1) ++other_live;
                    else if (board[i-1][j] <= 0) ++other_die;
                }
                if (i > 0 && j < cols - 1) {
                    if (board[i-1][j+1] >= 1) ++other_live;
                    else if (board[i-1][j+1] <= 0) ++other_die;
                }
                if (j > 0) {
                    if (board[i][j-1] >= 1) ++other_live;
                    else if (board[i][j-1] <= 0) ++other_die;
                }
                if (j < cols - 1) {
                    if (board[i][j+1] >= 1) ++other_live;
                    else if (board[i][j+1] <= 0) ++other_die;
                }
                if (i < rows - 1 && j > 0) {
                    if (board[i+1][j-1] >= 1) ++other_live;
                    else if (board[i+1][j-1] <= 0) ++other_die;
                }
                if (i < rows - 1) {
                    if (board[i+1][j] >= 1) ++other_live;
                    else if (board[i+1][j] <= 0) ++other_die;
                }
                if (i < rows - 1 && j < cols - 1) {
                    if (board[i+1][j+1] >= 1) ++other_live;
                    else if (board[i+1][j+1] <= 0) ++other_die;
                }
                if (board[i][j]) {
                    if (other_live < 2 || other_live > 3) board[i][j] = 2;
                }
                else {
                    if (other_live == 3) board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};
