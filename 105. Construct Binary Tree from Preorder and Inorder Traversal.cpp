#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		if (preorder.size() == 1) return root;
		stack<TreeNode*> s;
		int pre_index = 1, in_index = 0;
		TreeNode* tmp;
		s.push(root);
		while (true) {
			if (inorder[in_index] == s.top()->val) {
				tmp = s.top();
				s.pop();
				in_index++;
				if (in_index == inorder.size()) break;
				if (s.size() > 0 && inorder[in_index] == s.top()->val) continue;
				tmp->right = new TreeNode(preorder[pre_index++]);
				s.push(tmp->right);
			}
			else {
				tmp = new TreeNode(preorder[pre_index++]);
				s.top()->left = tmp;
				s.push(tmp);
			}
		}
		return root;
    }
};
