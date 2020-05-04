#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        if (T.size() == 0) return ans;
        ans[T.size()-1] = 0;
        int right_max = T[T.size()-1];
        int tmp;
        for (int i=T.size()-2; i >= 0; --i) {
            if (T[i] >= right_max) {
                right_max = T[i];
            }
            else {
                tmp = 1;
                while (T[i+tmp] <= T[i]) {
                    tmp += ans[i+tmp];
                }
                ans[i] = tmp;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v{1,2,3,4,5,6,7,6,5,4,3,2,1};
    auto ans = Solution().dailyTemperatures(v);
    for (auto i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
