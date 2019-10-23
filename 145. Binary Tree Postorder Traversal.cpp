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
	struct StackNode {
		TreeNode* node;
		int timesPop;
		StackNode(TreeNode* n=NULL):node(n), timesPop(0) {}
	};

    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
        stack<StackNode> s;
		StackNode current(root);
		s.push(current);
		while (!s.empty()) {
			current = s.top();
			s.pop();
			if (current.timesPop == 2) {
				res.push_back(current.node->val);
			}
			else if (current.timesPop == 1) {
				current.timesPop++;
				s.push(current);
				if (current.node->right) s.push(StackNode(current.node->right));
			}
			else {
				current.timesPop++;
				s.push(current);
				if (current.node->left) s.push(StackNode(current.node->left));
			}
		}
		return res;
    }
};

int main() {
	Solution a;
	
	cout << a << endl;
	return 0;
}
