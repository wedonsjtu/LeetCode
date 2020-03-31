#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> ds(n, -1);
        for (int i=0; i < n; ++i) {
            if (leftChild[i] != -1 && !merge(ds, i, leftChild[i])) return false;
            if (rightChild[i] != -1 && !merge(ds, i, rightChild[i])) return false;
        }
        return ds[find(ds, 0)] == -n;
    }
    
    int find(vector<int> &s, int x) {
        if (s[x] < 0) return x;
        s[x] = find(s, s[x]);
        return s[x];
    }
    
    bool merge(vector<int> &s, int x, int y) {
        int x_root = find(s, x);
        int y_root = find(s, y);
        if (x_root == y_root) return false;
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
    vector<int> v{1,-1,-1};
    cout << (a.validateBinaryTreeNodes(3, v, v)?"true":"false") << endl;
    return 0;
}
