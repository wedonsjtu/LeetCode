#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        order(root, nodes);
        return balanceBST(nodes, 0, nodes.size()-1);
    }

    TreeNode* balanceBST(vector<int>& nodes, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        int mid = (begin + end) / 2;
        TreeNode* new_root = new TreeNode(nodes[mid]);
        new_root->left = balanceBST(nodes, begin, mid-1);
        new_root->right = balanceBST(nodes, mid+1, end);
        return new_root;
    }

    void order(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        order(root->left, nodes);
        nodes.push_back(root->val);
        order(root->right, nodes);
    }
};