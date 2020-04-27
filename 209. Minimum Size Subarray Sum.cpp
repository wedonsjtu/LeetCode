#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, l = 0, tmp = 0;
        for (int r=0; r < nums.size(); ++r) {
            if (nums[r] == s) return 1;
            tmp += nums[r];
            while (tmp >= s) {
                ans = min(ans, r - l + 1);
                tmp -= nums[l];
                ++l;
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};

int main() {
    vector<int> v{1,2,3,4,5,6,7,8};
    cout << Solution().minSubArrayLen(16, v) << endl;
    return 0;
}
