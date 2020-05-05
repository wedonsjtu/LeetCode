#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution here.
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int max_step = 0;
        zigZag(root, true, 0, max_step);
        // zigZag(root, false, 0, max_step);  // don't need this line
        return max_step;
    }
    
    void zigZag(TreeNode* root, bool isLeft, int now_step, int& max_step) {
        if (!root) return;
        max_step = max(now_step, max_step);
        if (isLeft) {
            zigZag(root->left, false, now_step+1, max_step);
            zigZag(root->right, true, 1, max_step);
        } else {
            zigZag(root->right, true, now_step+1, max_step);
            zigZag(root->left, false, 1, max_step);
        }
    }
};

namespace tree_io {

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

    string treeNodeToString(TreeNode* root) {
        if (root == nullptr) {
        return "[]";
        }

        string output = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
            output += "null, ";
            continue;
            }

            output += to_string(node->val) + ", ";
            q.push(node->left);
            q.push(node->right);
        }
        return "[" + output.substr(0, output.length() - 2) + "]";
    }

}

int main() {
    using namespace tree_io;
    string line = "[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]";
    TreeNode* root = tree_io::stringToTreeNode(line);
    auto ans = Solution().longestZigZag(root);
    cout << ans << endl;
    return 0;
}
