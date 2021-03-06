#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> flag(nums.size(), false);
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(nums, curr, flag, res);
        return res;
    }

    void backtracking(const vector<int> &nums, vector<int> &curr, vector<bool> &flag, vector<vector<int>> &res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i=0; i < nums.size(); ++i) {
            if (flag[i]) continue;
            curr.push_back(nums[i]);
            flag[i] = true;
            backtracking(nums, curr, flag, res);
            curr.pop_back();
            flag[i] = false;
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
