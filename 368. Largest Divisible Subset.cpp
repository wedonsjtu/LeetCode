#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> count(nums.size(), 0);
        vector<int> pre(nums.size(), 0);
        int max_count = 0;
        int max_index = 0;
        for (int i=nums.size()-1; i >= 0; --i) {
            for (int j=i; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 && count[i] <= count[j]) {
                    count[i] = count[j] + 1;
                    pre[i] = j;
                    if (count[i] > max_count) {
                        max_count = count[i];
                        max_index = i;
                    }
                }
            }
        }
        
        vector<int> ans;
        for (int i=0; i < max_count; ++i) {
            ans.push_back(nums[max_index]);
            max_index = pre[max_index];
        }
        return ans;
    }
};

int main() {
    vector<int> v{1,2,4,5,8,9};
    auto ans = Solution().largestDivisibleSubset(v);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
