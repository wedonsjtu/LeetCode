#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
    
    void backtracking(vector<int>& nums, size_t level, vector<vector<int>>& ans) {
        if (level == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i=level; i < nums.size(); ++i) {
            swap(nums[i], nums[level]);
            backtracking(nums, level+1, ans);
            swap(nums[i], nums[level]);
        }
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3};
    vector<vector<int>> ans = a.permute(v);
    for (auto &vec: ans) {
        for (auto element: vec) {
            cout << element << ' ';
        }
        cout << endl;
    }
    return 0;
}
