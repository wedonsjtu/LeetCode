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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
		preorderTraversal(root1, seq1);
		preorderTraversal(root2, seq2);
		return seq1 == seq2;
    }

	void preorderTraversal(TreeNode* root, vector<int>& res) {
		if (!root) return;
        stack<TreeNode*> s;
		s.push(root);
		TreeNode* current;
		while (!s.empty()) {
			current = s.top();
			s.pop();
			if (!current->left && !current->right) res.push_back(current->val);
			if (current->right) s.push(current->right);
			if (current->left) s.push(current->left);
		}
    }
};



class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};