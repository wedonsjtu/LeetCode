#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0, left_part = A[0] + 0;
        for (int i=1; i < A.size(); ++i) {
            ans = max(ans, left_part + A[i] - i);
            left_part = max(left_part, A[i] + i);
        }
        return ans;
    }
};

int main() {
    vector<int> v{8,1,5,2,6};
    auto ans = Solution().maxScoreSightseeingPair(v);
    cout << ans << endl;
    return 0;
}
