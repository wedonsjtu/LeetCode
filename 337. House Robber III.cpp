#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        return rob_pair(root).first;
    }
    
    pair<int, int> rob_pair(TreeNode* root) {
        if (!root) return {0, 0};
        pair<int, int> left = rob_pair(root->left);
        pair<int, int> right = rob_pair(root->right);
        return {max(left.first + right.first, left.second + right.second + root->val), left.first + right.first};
    }
};
