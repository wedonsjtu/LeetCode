#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = 0;
        int* const _last = new int[cols]{0};
        int* const _now = new int[cols]{0};
        int* last = _last;
        int* now = _now;
        int* tmp;
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    now[j] = 0;
                }
                else if (j == 0) {
                    now[j] = matrix[i][j];
                }
                else {
                    now[j] = min(now[j-1], min(last[j-1], last[j])) + 1;
                }
                ans += now[j];
            }
            tmp = last;
            last = now;
            now = tmp;
        }
        delete[] _last;
        delete[] _now;
        return ans;
    }
};

int main() {
    vector<vector<int>> m{{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << Solution().countSquares(m) << endl;
    return 0;
}
