#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int rob(vector<int>& nums) {
    //     if (nums.empty()) return 0;
    //     int rob_yes = nums[0], not_rob_yes = 0;  // yes means yesterday
    //     int rob_today = 0, not_rob_today = 0;
    //     for (int i = 1; i < nums.size(); ++i) {
    //         rob_today = not_rob_yes + nums[i];
    //         not_rob_today = max(rob_yes, not_rob_yes);
    //         rob_yes = rob_today;
    //         not_rob_yes = not_rob_today;
    //     }
    //     return max(rob_yes, not_rob_yes);
    // }
    
    int rob(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int i=0; i < nums.size(); ++i) {
            if (i % 2) odd = max(odd + nums[i], even);
            else even = max(even + nums[i], odd);
        }
        return max(odd, even);
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3,1};
    cout << a.rob(v) << endl;
    return 0;
}
