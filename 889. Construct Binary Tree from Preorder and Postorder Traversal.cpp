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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePost(pre, 0, pre.size()-1, 
                                    post, 0, post.size()-1);
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, int pre_b, int pre_e, 
                                   vector<int>& post, int post_b, int post_e) {
        if (pre_b > pre_e) return NULL;
        TreeNode* root = new TreeNode(pre[pre_b]);
        // no left and no right
        if (pre_b == pre_e) return root;
        int left_index = pre_b+1;
        int right_index = post_e-1;
        // no left but with right or no right but with left
        if (pre[left_index] == post[right_index]) {
            // think all nodes are in left tree
            root->left = constructFromPrePost(pre, left_index, pre_e,
                                             post, post_b, right_index);
            root->right = NULL;
        }
        // with both left and right
        else {
            // search where is right node
            int where_is_right = pre_b + 2;
            while (pre[where_is_right] != post[right_index]) {
                ++where_is_right;
            }
            int where_is_left = post_e - 2;
            while (pre[left_index] != post[where_is_left]) {
                --where_is_left;
            }
            root->left = constructFromPrePost(pre, left_index, where_is_right-1, 
                                              post, post_b, where_is_left);
            root->right = constructFromPrePost(pre, where_is_right, pre_e, 
                                               post, where_is_left+1, right_index);
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
    vector<int> pre{1,2,4,5,3,6,7};
    vector<int> post{4,5,2,6,7,3,1};
    auto ans = Solution().constructFromPrePost(pre, post);
    cout << tree_io::treeNodeToString(ans) << endl;
    return 0;
}
