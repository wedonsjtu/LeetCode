#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int left_sum = 0;
        int right_sum = accumulate(nums.begin(), nums.end(), 0);
        for (int left=0; left < nums.size(); ++left) {
            left_sum += nums[left];
            right_sum -= nums[left];
            if (left_sum > right_sum) {
                vector<int> res(nums.begin(), nums.begin()+left+1);
                return res;
            }
        }
        return vector<int>{};
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3,4,5,6};
    vector<int> ans = a.minSubsequence(v);
    for (auto i: ans) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
