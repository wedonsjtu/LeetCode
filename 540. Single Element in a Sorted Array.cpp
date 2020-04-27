#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if ((mid % 2 == 0) && (mid + 1 < nums.size()) && (nums[mid] == nums[mid+1]) ||
               (mid % 2 == 1) && (mid - 1 >= 0) && (nums[mid] == nums[mid-1])) {
                begin = mid + 1;
            }
            else end = mid - 1;
        }
        return nums[begin];
    }
};

int main() {
    vector<int> v{1,1,2,3,3,4,4,8,8};
    cout << Solution().singleNonDuplicate(v) << endl;
    return 0;
}
