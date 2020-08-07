#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    
private:
    void reverse(vector<int>& nums, int begin, int end) {
        int tmp;
        while (begin < end) {
            tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            ++begin;
            --end;
        }
    }
};

int main() {
    vector<int> nums{1,2,3,4,5,6,7};
    Solution().rotate(nums, 3);
    for (int i: nums) cout << i << ' ';
    cout << endl;
    return 0;
}
