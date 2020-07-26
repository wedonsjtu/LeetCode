#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        int a, b, c, d, tmpSum;
        for (a = 0; a < nums.size() - 3; ++a) {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            for (b = a + 1; b < nums.size() - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b-1]) continue;
                c = b + 1;
                d = nums.size() - 1;
                while (c < d) {
                    tmpSum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (tmpSum > target) {
                        --d;
                    }
                    else if (tmpSum < target) {
                        ++c;
                    }
                    else {
                        ans.push_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                        while (c + 1 < nums.size() && nums[c+1] == nums[c]) ++c;
                        while (d - 1 > b && nums[d-1] == nums[d]) --d;
                        ++c;
                        --d;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    auto ans = Solution().fourSum(nums, 0);
    for (auto& v: ans) {
        for (int i: v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
