#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {  // nums[mid] == nums[right]
                --right;
            }
        }
        return nums[left];  // now left = right
    }
};

int main() {
    vector<int> nums{4,5,6,7,0,1,2};
    auto ans = Solution().findMin(nums);
    cout << ans << endl;
    return 0;
}
