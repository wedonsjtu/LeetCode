#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;
        int i = 0, j = 0;
        int m = matrix.size(), n = matrix[0].size();
        bool upright = true;
        while (i < m && j < n) {
            ans.push_back(matrix[i][j]);
            if (upright) {
                --i;
                ++j;
                if (j >= n) {
                    i += 2;
                    j = n - 1;
                    upright = false;
                }
                if (i < 0) {
                    i = 0;
                    upright = false;
                }
            }
            else {
                ++i;
                --j;
                if (i >= m) {
                    i = m - 1;
                    j += 2;
                    upright = true;
                }
                if (j < 0) {
                    j = 0;
                    upright = true;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9}};
    for (auto& v: m) {
        for (int i: v) cout << i << ' ';
        cout << endl;
    }
    cout << endl;
    auto ans = Solution().findDiagonalOrder(m);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
