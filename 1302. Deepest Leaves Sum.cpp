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

// Solution here.
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        int deepest = 0;
        int ans = 0;
        int now_depth = 0;
        stack<TreeNode*> s;
        stack<int> levels;
        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                levels.push(now_depth);
                root = root->left;
                now_depth++;
            }
            else {
                root = s.top();
                s.pop();
                now_depth = levels.top();
                levels.pop();
                if (now_depth > deepest) {
                    deepest = now_depth;
                    ans = root->val;
                } else if (now_depth == deepest) {
                    ans += root->val;
                }
                root = root->right;
                now_depth++;
            }
        }
        return ans;
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
    string line = "[1,2,3,4,5,null,6,7,null,null,null,null,8]";
    TreeNode* root = tree_io::stringToTreeNode(line);
    auto ans = Solution().deepestLeavesSum(root);
    cout << ans << endl;
    return 0;
}
