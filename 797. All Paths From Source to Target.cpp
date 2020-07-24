#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph, 0, path, ans);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int currNode, vector<int>& path, vector<vector<int>>& ans) {
        if (currNode == graph.size() - 1) {
            path.push_back(currNode);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(currNode);
        for (int node: graph[currNode]) {
            dfs(graph, node, path, ans);
        }
        path.pop_back();
    }
};

int main() {
    vector<vector<int>> graph{{1,2}, {3}, {3}, {}};
    auto ans = Solution().allPathsSourceTarget(graph);
    for (auto& v: ans) {
        for (int i: v) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
