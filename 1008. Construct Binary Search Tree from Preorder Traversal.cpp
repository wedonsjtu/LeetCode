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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return NULL;
        return bstFromPreorder(preorder, 0, preorder.size()-1);
    }

    TreeNode* bstFromPreorder(const vector<int>& preorder, int begin, int end) {
        if (begin > end) return NULL;
        TreeNode* root = new TreeNode(preorder[begin]);
        if (begin == end) return root;
        // find mid
        int begin_mid = begin + 1, end_mid = end, mid;
        while (begin_mid <= end_mid) {
            mid = (begin_mid + end_mid) / 2;
            if (preorder[mid] > preorder[begin]) {
                end_mid = mid - 1;
            }
            else {
                begin_mid = mid + 1;
            }
        }
        root->left = bstFromPreorder(preorder, begin+1, begin_mid-1);
        root->right = bstFromPreorder(preorder, begin_mid, end);
        return root;
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

int main() {
    // string line = "[8,5,1,7,10,12]";
    // TreeNode* root = stringToTreeNode(line);
    vector<int> v{8,5,1,7,10,12};
    auto ans = Solution().bstFromPreorder(v);
    cout << ans->val << ' ' << ans->left->val << ' ' << ans->right->val << endl;
    return 0;
}
