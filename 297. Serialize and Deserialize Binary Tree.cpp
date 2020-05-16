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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        ss << '[';
        TreeNode* tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (!tmp) {
                ss << "null" << ',';
                continue;
            }
            ss << tmp->val << ',';
            q.push(tmp->left);
            q.push(tmp->right);
        }
        ss << ']';
        // cout << ss.str() << endl;
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        stringstream ss;
        ss << data.substr(1, data.size()-2);
        string s;
        getline(ss, s, ',');
        if (s == "null") return NULL;
        TreeNode* root = new TreeNode(stoi(s)), *tmp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (!getline(ss, s, ',')) break;
            if (s != "null") {
                tmp->left = new TreeNode(stoi(s));
                q.push(tmp->left);
            }
            if (!getline(ss, s, ',')) break;
            if (s != "null") {
                tmp->right = new TreeNode(stoi(s));
                q.push(tmp->right);
            }
        }
        return root;
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
    string line = "[3,9,20,null,null,15,7]";
    TreeNode* root = tree_io::stringToTreeNode(line);
    cout << "Origin: " << tree_io::treeNodeToString(root) << endl;
    Codec c;
    auto ans = c.deserialize(c.serialize(root));
    cout << "Now:    " << tree_io::treeNodeToString(ans) << endl;
    return 0;
}
