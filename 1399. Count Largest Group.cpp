#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> m, m2;
        int sum1;
        for (int i=1; i<=n;++i) {
            sum1 = 0;
            int j = i;
            while (j != 0) {
                sum1 += j % 10;
                j /= 10;
            }
            // cout << i << ' ' << sum1 << endl;
            if (m.find(sum1) == m.end()) {
                m[sum1] = 1;
            }
            else {
                m[sum1] += 1;
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (m2.find(it->second) == m2.end()) {
                m2[it->second] = 1;
            }
            else {
                m2[it->second] += 1;
            }
        }
        int ans = 0;
        int now = 0;
        for (auto it = m2.begin(); it != m2.end(); ++it) {
            if (now < it->first) {
                ans = it->second;
                now = it->first;
            }
        }
        // int ans = 0;
        
        return ans;
    }
};

int main() {
    Solution a;
    cout << a.countLargestGroup(13) << endl;
    return 0;
}
