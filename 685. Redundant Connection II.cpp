#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // https://leetcode.com/problems/redundant-connection-ii/discuss/278105/topic
        vector<int> ds(edges.size()+1, -1);  // can be optimized
        vector<int> parent(edges.size()+1, -1);
        vector<int> edge1, edge2, error_edge;
        for (auto &edge: edges) {
            if (parent[edge[1]] != -1) {  // has a father before
                edge1.push_back(parent[edge[1]]);
                edge1.push_back(edge[1]);
                edge2.push_back(edge[0]);
                edge2.push_back(edge[1]);
            }  // skip this edge
            else {
                parent[edge[1]] = edge[0];
                if (!merge(ds, edge[0], edge[1])) {
                    error_edge.push_back(edge[0]);
                    error_edge.push_back(edge[1]);
                }
            }
        }
        if (edge1.empty()) return error_edge;
        if (error_edge.empty()) return edge2;
        return edge1;
    }
    
    // find operation in disjoint-set
    int find(vector<int> &s, int x) {
        // If the value is a negative number, it's root of a set.
        if (s[x] < 0) return x;
        s[x] = find(s, s[x]);  // path_compression strategy
        return s[x];
    }
    
    // union_by_size operation in disjoint-set
    bool merge(vector<int> &s, int x, int y) {
        int x_root = find(s, x);
        int y_root = find(s, y);
        if (x_root == y_root) return false;  // They have already connected.
        if (s[x_root] > s[y_root]) {
            s[y_root] += s[x_root];
            s[x_root] = y_root;
        }
        else {
            s[x_root] += s[y_root];
            s[y_root] = x_root;
        }
        return true;
    }
};

int main() {
    Solution a;
    vector<vector<int>> v{vector<int>{2,1}, vector<int>{3,1}, vector<int>{4,2}, vector<int>{1,4}};
    auto ans = a.findRedundantDirectedConnection(v);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
