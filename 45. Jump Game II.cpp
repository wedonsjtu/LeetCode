#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // if (nums.size() == 0) return 0;
        int best = 0;
        int can_jump = 0;
        int ans = 0;
        for (int i=0; i < nums.size() - 1; ++i) {
            can_jump = max(can_jump, i + nums[i]);
            if (i == best) {
                ++ans;
                best = can_jump;
                if (best >= nums.size()-1) return ans;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v{1,1,3,5,6};
    cout << Solution().jump(v) << endl;
    return 0;
}
