#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for (int i=1; i <= num; ++i) {
            ans[i] = ans[i&(i-1)] + 1;
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().countBits(10);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
