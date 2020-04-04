#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        for (size_t i=0; i <= nums.size(); ++i) {
            backtracking(nums, i, 0, curr, ans);
        }
        return ans;
    }

    void backtracking(vector<int>& nums, size_t subset_len, size_t level, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == subset_len) {
            ans.push_back(curr);
            return;
        }
        for (size_t i=level; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backtracking(nums, subset_len, i+1, curr, ans);
            curr.pop_back();
        }
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3};
    vector<vector<int>> ans = a.subsets(v);
    cout << "Size: " << ans.size() << endl;
    for (auto &vec: ans) {
        for (auto element: vec) {
            cout << element << ' ';
        }
        cout << endl;
    }
    return 0;
}
