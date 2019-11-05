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
    struct LCANode {
		TreeNode* node;
		int timesPop;
		bool findx;
		bool findy;
		LCANode(TreeNode* n=NULL):node(n), timesPop(0), findx(false), findy(false) {}
	};

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
        stack<LCANode> s;
		bool xfind = false;
		bool yfind = false;
		LCANode current(root);
		s.push(current);
		while (!s.empty()) {
			current = s.top();
			s.pop();
			current.timesPop++;
			if (current.timesPop == 3) {
				if (xfind) current.findx = true;
				if (yfind) current.findy = true;
				xfind = current.findx;
				yfind = current.findy;
				if (current.findx && current.findy) return current.node;
				continue;
			}
			if (current.node->val == p->val) {
				xfind = true;
				current.findx = true;
			}
			if (current.node->val == q->val) {
				yfind = true;
				current.findy = true;
			}
			if (current.timesPop == 2) {
				if (xfind) current.findx = true;
				if (yfind) current.findy = true;
				s.push(current);
				xfind = false;
				yfind = false;
				if (current.node->right) s.push(LCANode(current.node->right));
			}
			else {
				s.push(current);
				xfind = false;
				yfind = false;
				if (current.node->left) s.push(LCANode(current.node->left));
			}
		}
		return NULL;
    }
};
