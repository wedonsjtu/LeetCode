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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
        stack<TreeNode*> s;
		s.push(root);
		TreeNode* current;
		while (!s.empty()) {
			current = s.top();
			s.pop();
			res.push_back(current->val);
			if (current->right) s.push(current->right);
			if (current->left) s.push(current->left);
		}
		return res;
    }
};

int main() {
	Solution a;
	
	cout << a << endl;
	return 0;
}
