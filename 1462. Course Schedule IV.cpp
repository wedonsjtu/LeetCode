#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        if (queries.empty()) return ans;
        vector<vector<int>> g(n, vector<int>(n, 0));
        // 1: is prerequisite
        // 0: unknown
        // -1: not prerequisite
        for (auto& pre: prerequisites) {
            g[pre[0]][pre[1]] = 1;
            g[pre[1]][pre[0]] = -1;
        }
        for (auto& q: queries) {
            vector<int> currList;
            ans.push_back(dfsCheck(g, q[0], q[1], currList));
        }
        return ans;
    }
    
private:
    bool dfsCheck(vector<vector<int>>& g, int from, int to, vector<int>& currList) {
        if (g[from][to] == 1) {
            for (int f: currList) {
                g[f][to] = 1;
                g[to][f] = -1;
            }
            return true;
        }
        if (g[from][to] == -1) {
            return false;
        }
        currList.push_back(from);
        for (int t=0; t < g.size(); ++t) {
            if (g[from][t] == 1) {
                if (dfsCheck(g, t, to, currList)) return true;
            }
        }
        g[from][to] = -1;
        currList.pop_back();
        return false;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> prerequisites{{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> queries{{0,4},{4,0},{1,3},{3,0}};
    auto ans = Solution().checkIfPrerequisite(n, prerequisites, queries);
    cout << boolalpha;
    for (bool b: ans) cout << b << ' ';
    cout << endl;
    return 0;
}
