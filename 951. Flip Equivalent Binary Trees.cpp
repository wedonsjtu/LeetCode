#include <iostream>
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (!root1) return !root2;
		if (!root2) return !root1;
        if (root1->val != root2->val) return false;
		return ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || 
			(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
    }
};
