#include <iostream>
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
	struct QueueNode {
		TreeNode* node;
		int level;
		QueueNode(TreeNode* n=NULL, int times=1):node(n), level(times) {}
	};

    int maxLevelSum(TreeNode* root) {
		int level_ans = 1, level_ans_sum = 0;
		queue<QueueNode> q;
		int now_level = 0, now_sum = 0;
		QueueNode current(root, 1);
		q.push(current);
		while (!q.empty()) {
			current = q.front();
			q.pop();
			if (current.level > now_level) {
				if (now_sum > level_ans_sum) {
					level_ans_sum = now_sum;
					level_ans = now_level;
				}
				now_sum = current.node->val;
			}
			else {
				now_sum += current.node->val;
			}
			now_level = current.level;
			if (current.node->left) q.push(QueueNode(current.node->left, now_level + 1));
			if (current.node->right) q.push(QueueNode(current.node->right, now_level + 1));
		}
		if (now_sum > level_ans_sum) {
			level_ans_sum = now_sum;
			level_ans = now_level;
		}
		return level_ans;
    }
};
