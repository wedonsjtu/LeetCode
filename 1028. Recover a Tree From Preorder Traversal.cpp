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
    TreeNode* recoverFromPreorder(string S) {
		if (S.size() == 0) return NULL;
		stack<TreeNode*> st;
		TreeNode* tmp;
		int depth, digit_len;
		for (int i=0; i < S.size(); i += digit_len) {
			depth = 0;
			digit_len = 0;
			while (S[i] == '-') {
				++depth;
				++i;
			}
			while (i+digit_len < S.size() && S[i+digit_len] != '-') ++digit_len;
			tmp = new TreeNode(stoi(S.substr(i, digit_len)));
			while (st.size() > depth) st.pop();
			if (!st.empty()) {
				if (!st.top()->left) st.top()->left = tmp;
				else st.top()->right = tmp;
			}
			st.push(tmp);
		}
		while (st.size() > 1) st.pop();
		return st.top();
    }
};
