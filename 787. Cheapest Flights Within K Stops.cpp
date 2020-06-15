#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
        for (auto& flight: flights) {
            g[flight[0]][flight[1]] = flight[2];
        }
        unordered_map<int, int> cost;
        cost[src] = 0;
        for (int i=0; i <= K; ++i) {
            unordered_map<int, int> cost_copy(cost);
            for (auto it=cost_copy.begin(); it != cost_copy.end(); ++it) {
                auto start = it->first;
                for (int j=0; j < n; ++j) {
                    if (g[start][j] == INT_MAX) continue;
                    if (cost.find(j) == cost.end()) cost[j] = g[start][j] + it->second;
                    else cost[j] = min(cost[j], g[start][j] + it->second);
                }
            }
        }
        if (cost.find(dst) == cost.end()) return -1;
        return cost[dst];
    }
};

int main() {
    vector<vector<int>> m{{0,1,100},{1,2,100},{0,2,500}};
    cout << Solution().findCheapestPrice(3, m, 0, 2, 0) << endl;
    cout << Solution().findCheapestPrice(3, m, 0, 2, 1) << endl;
    return 0;
}
