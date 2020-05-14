#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int mask = 0;
        for (int num: nums) mask ^= num;
        int last_bit = mask & (-mask);
        for (int num: nums) {
            if (num & last_bit) {
                ans[0] ^= num;
            }
        }
        ans[1] = ans[0] ^ mask;
        return ans;
    }
};

int main() {
    vector<int> nums{2147483647,-2147483648,-2147483648,2};
    auto ans = Solution().singleNumber(nums);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
