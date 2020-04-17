#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* node) {
        // similar to MorrisInorder
        vector<int> res;
        TreeNode* pre;
        while (node) {
            if (!node->left) {
                res.push_back(node->val);
                node = node->right;
            }
            else {  // with left child
                pre = node->left;
                while (pre->right && pre->right != node) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    res.push_back(node->val);
                    pre->right = node;
                    node = node->left;
                }
                else {
                    pre->right = NULL;  // make right pointer null again
                    node = node->right;
                }
            }
        }
        return res;
    }
    
	vector<int> preorderTraversalWithStack(TreeNode* root) {
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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void println(const vector<int>& v) {
    for (int i: v) cout << i << ' ';
    cout << endl;
}

int main() {
    Solution tra;
    string nodelist = "[3,9,20,11,23,15,7]";
    TreeNode* root = stringToTreeNode(nodelist);
    vector<int> res;
    res = tra.preorderTraversal(root);
    println(res);
    return 0;
}
