#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0, sum = 0;
        m[0] = 1;
        for (int num: nums) {
            sum += num;
            if (m.find(sum-k) != m.end()) {
                count += m[sum-k];
            }
            if (m.find(sum) == m.end()) {
                m[sum] = 1;
            }
            else {
                m[sum] += 1;
            }
        }
        return count;
    }
};

int main() {
    vector<int> v{0,0,0};
    cout << Solution().subarraySum(v, 0) << endl;
    return 0;
}
