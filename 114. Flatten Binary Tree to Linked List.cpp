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
    void flatten(TreeNode* root) {
        TreeNode* current = root;
		TreeNode* tmp;
		while (current) {
			if (current->left) {
				tmp = current->left;
				while (tmp->right) tmp = tmp->right;
				tmp->right = current->right;
				current->right = current->left;
				current->left = NULL;
			}
			current = current->right;
		}
    }
};
