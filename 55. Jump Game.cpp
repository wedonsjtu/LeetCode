#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_step = 0;
        for (int i=0; i < nums.size(); ++i) {
            if (max_step < i) return false;
            max_step = max(max_step, i + nums[i]);
            if (max_step >= nums.size()-1) return true;
        }
        return true;
    }
};

int main() {
    vector<int> v{3,2,1,0,4};
    vector<int> v1{2,3,1,0,4};
    cout << boolalpha << Solution().canJump(v) << endl;
    cout << boolalpha << Solution().canJump(v1) << endl;
    return 0;
}
