#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
private:
    bool dfs(vector<pair<bool, bool>>& g, vector<vector<int>>& graph, int n1) {
        for (int n2: graph[n1]) {
            if (g[n2].first) {
                if (g[n2].second == g[n1].second) {
                    return false;
                }
            }
            else {
                g[n2].first = true;
                g[n2].second = !(g[n1].second);
                if (!dfs(g, graph, n2)) {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // isVisited color
        vector<pair<bool, bool>> g(graph.size(), {false, false});
        queue<int> q;
        for (int i=0; i < graph.size(); ++i) {
            if (g[i].first || graph[i].empty()) continue;
            g[i].first = true;
            g[i].second = false;
            if (!dfs(g, graph, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartiteBFS(vector<vector<int>>& graph) {
        // isVisited color
        vector<pair<bool, bool>> g(graph.size(), {false, false});
        queue<int> q;
        for (int i=0; i < graph.size(); ++i) {
            if (g[i].first || graph[i].empty()) continue;
            g[i].first = true;
            g[i].second = false;
            q.push(i);
            while (!q.empty()) {
                int n1 = q.front();
                q.pop();
                for (int n2: graph[n1]) {
                    if (g[n2].first) {
                        if (g[n2].second == g[n1].second) {
                            return false;
                        }
                    }
                    else {
                        g[n2].first = true;
                        g[n2].second = !(g[n1].second);
                        q.push(n2);
                    }
                }
            }
        }
        return true;
    }
    
    bool isBipartiteDFS(vector<vector<int>>& graph) {
        // isVisited color
        vector<pair<bool, bool>> g(graph.size(), {false, false});
        stack<int> s;
        for (int i=0; i < graph.size(); ++i) {
            if (g[i].first || graph[i].empty()) continue;
            g[i].first = true;
            g[i].second = false;
            s.push(i);
            while (!s.empty()) {
                int n1 = s.top();
                s.pop();
                for (int n2: graph[n1]) {
                    if (g[n2].first) {
                        if (g[n2].second == g[n1].second) {
                            return false;
                        }
                    }
                    else {
                        g[n2].first = true;
                        g[n2].second = !(g[n1].second);
                        s.push(n2);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> g1{{1,3},{0,2},{1,3},{0,2}};
    vector<vector<int>> g2{{1,2,3},{0,2},{0,1,3},{0,2}};
    Solution sol;
    cout << boolalpha;
    cout << sol.isBipartite(g1) << ' ';
    cout << sol.isBipartiteBFS(g1) << ' ';
    cout << sol.isBipartiteDFS(g1) << endl;
    cout << sol.isBipartite(g2) << ' ';
    cout << sol.isBipartiteBFS(g2) << ' ';
    cout << sol.isBipartiteDFS(g2) << endl;
    return 0;
}
