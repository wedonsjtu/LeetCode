#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], subs[9];
        int i, j, sub_index;
        char now;
        for (i=0; i < 9; ++i) {
            for (j=0; j < 9; ++j) {
                now = board[i][j];
                if (now == '.') continue;
                if (rows[i].find(now) != rows[i].end()) return false;
                rows[i].insert(now);
                if (cols[j].find(now) != cols[j].end()) return false;
                cols[j].insert(now);
                sub_index = i / 3 * 3 + j / 3;
                if (subs[sub_index].find(now) != subs[sub_index].end()) return false;
                subs[sub_index].insert(now);
            }
        }
        return true;
    }
};
