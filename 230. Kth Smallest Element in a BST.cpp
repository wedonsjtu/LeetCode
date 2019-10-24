#include <iostream>
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
	struct StackNode {
		TreeNode* node;
		int timesPop;
		StackNode(TreeNode* n=NULL):node(n), timesPop(0) {}
	};

    int kthSmallest(TreeNode* root, int k) {
        stack<StackNode> s;
		StackNode current(root);
		s.push(current);
		while (!s.empty()) {
			current = s.top();
			s.pop();
			if (current.timesPop == 0) {
				current.timesPop++;
				s.push(current);
				if (current.node->left) s.push(StackNode(current.node->left));
			}
			else {
				k--;
				if (k == 0) return current.node->val;
				if (current.node->right) s.push(StackNode(current.node->right));
			}
		}
	return 0;
    }
};
