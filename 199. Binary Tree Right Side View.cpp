#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		queue<int> q_depth;
		int now_level = -1;
		TreeNode* current = root;
		q.push(root);
		q_depth.push(now_level+1);
		while (!q.empty()) {
			current = q.front();
			q.pop();
			if (now_level < q_depth.front()) {
				res.push_back(current->val);
			}
			now_level = q_depth.front();
			q_depth.pop();
			if (current->right) {
				q.push(current->right);
				q_depth.push(now_level+1);
			}
			if (current->left) {
				q.push(current->left);
				q_depth.push(now_level+1);
			}
		}
		return res;
    }
};