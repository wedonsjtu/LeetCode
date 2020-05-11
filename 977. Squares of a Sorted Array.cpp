#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty()) return A;
        vector<int> ans(A.size(), 0);
        int index = A.size()-1;
        int left = 0, right = A.size()-1;
        int left2, right2;
        while (left <= right) {
            left2 = A[left] * A[left];
            right2 = A[right] * A[right];
            if (left2 >= right2) {
                ans[index--] = left2;
                ++left;
            }
            else {
                ans[index--] = right2;
                --right;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v{-19,-17,-12,-11,-8,-5,-4,-3,-2,-1,1,2,6,7,9,11,16,17,18,19};
    auto ans = Solution().sortedSquares(v);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
