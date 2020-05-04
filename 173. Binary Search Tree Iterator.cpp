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
class BSTIterator {
private:
    stack<TreeNode*> s;
    TreeNode* curr;
    
    void inorder(TreeNode* root) {  // useless
        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                cout << root->val << endl;
                root = root->right;
            }
        }
    }
    
public:
    BSTIterator(TreeNode* root):s(), curr(root) {
        
    }
    
    /** @return the next smallest number */
    int next() {
        while (!s.empty() || curr) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                s.pop();
                int tmp = curr->val;
                curr = curr->right;
                return tmp;
            }
        }
        return -1;  // invalid
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (curr) return true;
        return !s.empty();
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
    string line = "[1]";
    TreeNode* root = tree_io::stringToTreeNode(line);
    BSTIterator I(root);
    cout << boolalpha;
    cout << I.hasNext() << endl;
    cout << I.next() << endl;
    cout << I.hasNext() << endl;
    return 0;
}
