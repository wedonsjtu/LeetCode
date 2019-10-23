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
	struct QueueNode {
		TreeNode* node;
		int level;
		QueueNode(TreeNode* n=NULL, int times=0):node(n), level(times) {}
	};

    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<QueueNode> q;
		int now_level = 0;
		QueueNode current(root, 0);
		q.push(current);
		while (!q.empty()) {
			current = q.front();
			q.pop();
			now_level = current.level;
			if (now_level >= res.size()) {
				res.push_back(vector<int>());
				res[now_level].push_back(current.node->val);
			}
			else {
				res[now_level].push_back(current.node->val);
			}
			if (current.node->left) q.push(QueueNode(current.node->left, now_level + 1));
			if (current.node->right) q.push(QueueNode(current.node->right, now_level + 1));
		}
		return res;
    }
};

int main() {
	Solution a;
	
	cout << a << endl;
	return 0;
}
