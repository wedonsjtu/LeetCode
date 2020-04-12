#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n < 0) return 0;
        int ans = 0;
        vector<bool> col(n, false), lud(2*n-1, false), rud(2*n-1, false);
        backtracking(ans, col, lud, rud, 0, n);
        return ans;
    }

    void backtracking(int &ans, vector<bool> &col, vector<bool> &lud, vector<bool> &rud, int r, int n) {
        if (r == n) {
            ++ans;
            return;
        }
        for (int c=0; c < n; ++c) {
            if (col[c] || lud[n-r+c-1] || rud[r+c]) continue;
            col[c] = lud[n-r+c-1] = rud[r+c] = true;
            backtracking(ans, col, lud, rud, r+1, n);
            col[c] = lud[n-r+c-1] = rud[r+c] = false;
        }
    }
};

int main() {
    Solution a;
    for (int i = 1; i <= 12; ++i)
        cout << i << ' ' << a.totalNQueens(i) << endl;
    return 0;
}
