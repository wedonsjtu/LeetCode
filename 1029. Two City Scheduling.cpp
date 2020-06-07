#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1] - a[0] < b[1] - b[0];
        });
        int ans = 0;
        for (int i = 0; i < costs.size(); ++i) {
            if (i < costs.size() / 2) ans += costs[i][1];
            else ans += costs[i][0];
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> costs{{10,20},{30,200},{400,50},{30,20}};
    auto ans = Solution().twoCitySchedCost(costs);
    cout << ans << endl;
    return 0;
}
