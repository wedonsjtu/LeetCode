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
public:  // Solution 1
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        enum STATUS {XX, OX, OO};  // both unchecked; only left checked; both checked
        bool isOneFound = false;
        TreeNode* LCANode;
        stack<TreeNode*> ts;
        stack<STATUS> ss;
        TreeNode* tmpNode;
        STATUS tmpStatus;
        ts.push(root);
        ss.push(STATUS::XX);
        while (!ts.empty()) {
            tmpNode = ts.top();
            tmpStatus = ss.top();
            if (tmpStatus == STATUS::OO) {
                ts.pop();
                ss.pop();
                if (LCANode == tmpNode) {
                    if (ts.empty()) return NULL;
                    LCANode = ts.top();
                }
            } else if (tmpStatus == STATUS::XX) {
                if (tmpNode == p || tmpNode == q) {
                    if (isOneFound) {
                        return LCANode;
                    } else {
                        isOneFound = true;
                        LCANode = tmpNode;
                    }
                }
                ss.pop();
                ss.push(STATUS::OX);
                if (tmpNode->left) {
                    ts.push(tmpNode->left);
                    ss.push(STATUS::XX);
                }
            } else {  // tmpStatus == STATUS::OX
                ss.pop();
                ss.push(STATUS::OO);
                if (tmpNode->right) {
                    ts.push(tmpNode->right);
                    ss.push(STATUS::XX);
                }
            }
        }
        return NULL;
    }

private: // another solution
    struct LCANode {
        TreeNode* node;
        int timesPop;
        bool findx;
        bool findy;
        LCANode(TreeNode* n=NULL):node(n), timesPop(0), findx(false), findy(false) {}
    };

public:
    TreeNode* lowestCommonAncestor_Solution_2(TreeNode* root, TreeNode* p, TreeNode* q) {
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
            if (current.node == p) {
                xfind = true;
                current.findx = true;
            }
            if (current.node == q) {
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
    auto ans = Solution().lowestCommonAncestor(root, root->left, root->right->left);
    cout << ans->val << endl;
    return 0;
}
