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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		TreeNode* tmp;
		int q_len;
		bool now_level = false;
		q.push(root);
		while (!q.empty()) {
			q_len = q.size();
			vector<int> current_layer(q_len);
			for (int i=0; i < q_len; ++i) {
				tmp = q.front();
				q.pop();
				if (!now_level) {
					current_layer[i] = tmp->val;
				}
				else {
					current_layer[q_len - i - 1] = tmp->val;
				}
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
			res.push_back(current_layer);
			now_level = !now_level;
		}
		return res;
    }
};
