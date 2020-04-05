#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0;
        for (int i=0; i < satisfaction.size(); ++i) {
            int sum = 0;
            for (int j=i; j < satisfaction.size(); ++j) {
                sum += (j-i+1) * satisfaction[j];
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3,4};
    cout << a.maxSatisfaction(v) << endl;
    return 0;
}
