#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i < n; ++i) {
            if (nums[i] <= 0) nums[i] = n + 1;
        }
        int num;
        for (int i=0; i < n; ++i) {
            num = abs(nums[i]);
            if (num <= n) {
                nums[num-1] = -abs(nums[num-1]);
            }
        }
        for (int i=0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main() {
    vector<int> nums{3,4,-1,1};
    auto ans = Solution().firstMissingPositive(nums);
    cout << ans << endl;
    return 0;
}
