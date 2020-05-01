#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        int mid;
        while (begin < end) {
            mid = begin + (end - begin) / 2;
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};

int main() {
    vector<int> nums{1,2,3,4,5};
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}
