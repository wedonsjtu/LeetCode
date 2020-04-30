#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int ans = 0, one_bits;
        for (int i=0; i < 32; ++i) {
            one_bits = 0;
            for (int num: nums) {
                if ((num >> i) & 1) one_bits++;
            }
            ans += one_bits * (nums.size()-one_bits);
        }
        return ans;
    }
};

int main() {
    vector<int> nums{4, 14, 2};
    cout << Solution().totalHammingDistance(nums) << endl;
    return 0;
}
