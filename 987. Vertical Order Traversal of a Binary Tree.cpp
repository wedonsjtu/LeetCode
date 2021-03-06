#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, multiset<pair<int, int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, INT_MIN}});
        TreeNode* tmpNode;
        int tmpX, tmpY;
        while (!q.empty()) {
            tmpNode = q.front().first;
            tmpX = q.front().second.first;
            tmpY = q.front().second.second;
            q.pop();
            m[tmpX].insert({tmpY, tmpNode->val});
            if (tmpNode->left) {
                q.push({tmpNode->left, {tmpX - 1, tmpY + 1}});
            }
            if (tmpNode->right) {
                q.push({tmpNode->right, {tmpX + 1, tmpY + 1}});
            }
        }
        for (auto it=m.begin(); it != m.end(); ++it) {
            ans.push_back(vector<int>());
            for (auto& p: it->second) {
                ans.back().push_back(p.second);
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
    string line = "[3,9,20,null,null,15,7]";
    TreeNode* root = tree_io::stringToTreeNode(line);
    auto ans = Solution().verticalTraversal(root);
    for (auto& v: ans) {
        for (int i: v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
