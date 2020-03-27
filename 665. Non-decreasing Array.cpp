#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        bool flag = false;
        int index = 0;
        for (int i=0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                if (flag) return false;
                flag = true;
                index = i;
            }
        }
        if (!flag) return true;
        if (index == 0) return true;
        if (index == nums.size() - 2) return true;
        if (nums[index-1] <= nums[index+1]) return true;
        if (nums[index] <= nums[index+2]) return true;
        return false;
    }
};

int main() {
    Solution a;
    vector<int> v{4,2,3};
    cout << a.checkPossibility(v) << endl;
    return 0;
}
