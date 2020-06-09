#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int find(vector<int>& ds, int x) {
        if (ds[x] < 0) return x;
        ds[x] = find(ds, ds[x]);
        return ds[x];
    }
    
    bool merge(vector<int>& ds, int x, int y) {
        int x_root = find(ds, x);
        int y_root = find(ds, y);
        if (x_root == y_root) return false;
        if (ds[x_root] > ds[y_root]) {
            ds[y_root] += ds[x_root];
            ds[x_root] = y_root;
        } else {
            ds[x_root] += ds[y_root];
            ds[y_root] = x_root;
        }
        return true;
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> ds(26, -1);
        for (string& eq: equations) {
            if (eq[1] == '=') {
                merge(ds, eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (string& eq: equations) {
            if (eq[1] == '!') {
                if (find(ds, eq[0] - 'a') == find(ds, eq[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<string> equations{"a==b", "b!=c", "c==a"};
    auto ans = Solution().equationsPossible(equations);
    cout << boolalpha << ans << endl;
    return 0;
}
