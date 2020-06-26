#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int num: nums) {
            once = ~twice & (once ^ num);
            twice = ~once & (twice ^ num);
        }
        return once;
    }
};

int main() {
    vector<int> v{1,2,3,4,2,3,4,2,3,4};
    auto ans = Solution().singleNumber(v);
    cout << ans << endl;
    return 0;
}
