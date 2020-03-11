#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        vector<int> ans(2, 0);
        for (int i=0; i < nums.size(); ++i) {
            if (s.find(target-nums[i]) == s.end()) {
                s[nums[i]] = i;
            }
            else {
                ans[0] = s[target-nums[i]];
                ans[1] = i;
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> v = {2, 7, 11, 15};
    vector<int> ans = a.twoSum(v, 13);
    cout << ans[0] << ' ' << ans[1] << endl;
}
