#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int odd_first = 0, odd_not_first = 0;
        int even_first = nums[0], even_not_first = 0;
        for (int i=1; i < nums.size(); ++i) {
            if (i % 2) {
                if (i != nums.size() - 1)
                    odd_first = max(odd_first + nums[i], even_first);
                odd_not_first = max(odd_not_first + nums[i], even_not_first);
            }
            else {
                if (i != nums.size() - 1)
                    even_first = max(even_first + nums[i], odd_first);
                even_not_first = max(even_not_first + nums[i], odd_not_first);
            }
        }
        return max(max(odd_first, odd_not_first), max(even_first, even_not_first));
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3,1};
    cout << a.rob(v) << endl;
    return 0;
}
