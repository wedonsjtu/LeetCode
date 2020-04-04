#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{{}};
        size_t begin = 0;
        for (size_t i=0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i-1]) begin = 0;
            for (size_t end = ans.size(); begin < end; ++begin) {
                vector<int> tmp(ans[begin]);
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,2};
    vector<vector<int>> ans = a.subsetsWithDup(v);
    cout << "Size: " << ans.size() << endl;
    for (auto &vec: ans) {
        for (auto element: vec) {
            cout << element << ' ';
        }
        cout << endl;
    }
    return 0;
}
