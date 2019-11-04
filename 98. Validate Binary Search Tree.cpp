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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
		stack<TreeNode*> s;
		long long tmp_val = LONG_LONG_MIN;
		TreeNode* tmp = root;
		while (!s.empty() || tmp) {
			while (tmp) {
				s.push(tmp);
				tmp = tmp->left;
			}
			tmp = s.top();
			s.pop();
			if ((long long)(tmp->val) <= tmp_val) return false;
			tmp_val = tmp->val;
			tmp = tmp->right;
		}
		return true;
    }
};
