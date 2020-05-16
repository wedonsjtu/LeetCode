#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.empty()) return 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int arraySum = 0;
        int maxTmp = 0;
        int minTmp = 0;
        for (int i=0; i < A.size(); ++i) {
            maxTmp += A[i];
            maxSum = max(maxSum, maxTmp);
            if (maxTmp < 0) maxTmp = 0;
            minTmp += A[i];
            minSum = min(minSum, minTmp);
            if (minTmp > 0) minTmp = 0;
            arraySum += A[i];
        }
        if (maxSum > 0) {
            return max(maxSum, arraySum-minSum);
        }
        else {
            return maxSum;
        }
    }
};

int main() {
    vector<int> v{4,-4,5,-2,-1};
    auto ans = Solution().maxSubarraySumCircular(v);
    cout << ans << endl;
    return 0;
}
