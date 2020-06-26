#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            int sum;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l+1]) ++l;
                    while (l + 1 < r && nums[r] == nums[r-1]) --r;
                    ++l;
                    --r;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    auto ans = Solution().threeSum(nums);
    for (auto& v: ans) {
        for (auto n: v) {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}
