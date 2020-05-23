#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        int low, high;
        while (i < A.size() && j < B.size()) {
            low = max(A[i][0], B[j][0]);
            high = min(A[i][1], B[j][1]);
            if (low <= high) {
                ans.push_back(vector<int>{low, high});
            }
            if (A[i][1] < B[j][1]) ++i;
            else ++j;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> A{{1,2},{3,4}};
    vector<vector<int>> B{{2,3},{4,5}};
    auto ans = Solution().intervalIntersection(A, B);
    for (auto& interval: ans) cout << '[' << interval[0] << ',' << interval[1] << ']' << ' ';
    cout << endl;
    return 0;
}
