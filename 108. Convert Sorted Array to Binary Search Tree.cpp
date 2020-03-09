/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return sortedArrayWithRange(nums, 0, nums.size()-1);
//     }
    
//     TreeNode* sortedArrayWithRange(vector<int>& nums, int begin, int end) {
//         if (end < begin) return nullptr;
//         TreeNode* root = new TreeNode(nums[(begin+end)/2]);
//         root->left = sortedArrayWithRange(nums, begin, (begin+end)/2-1);
//         root->right = sortedArrayWithRange(nums, (begin+end)/2+1, end);
//         return root;
//     }
// };

#include <vector>
#include <stack>

class Solution {
public:
    struct StackNode {
        int left_range, right_range;
        TreeNode* node;
        StackNode(TreeNode* t, int l, int r): 
            node(t), left_range(l), right_range(r) {}
    };
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        stack<StackNode> s;
        TreeNode* root = new TreeNode(nums[(nums.size()-1)/2]);
        s.push(StackNode(root, 0, nums.size()-1));
        TreeNode* tmp_tree;
        while (!s.empty()) {
            StackNode tmp = s.top();
            s.pop();
            int mid = (tmp.left_range + tmp.right_range) / 2;
            if(mid > tmp.left_range) {
                tmp_tree = new TreeNode(nums[(tmp.left_range+mid-1)/2]);
                (tmp.node)->left = tmp_tree;
                s.push(StackNode(tmp_tree, tmp.left_range, mid-1));
            }
            if(mid < tmp.right_range) {
                tmp_tree = new TreeNode(nums[(tmp.right_range+mid+1)/2]);
                (tmp.node)->right = tmp_tree;
                s.push(StackNode(tmp_tree, mid+1, tmp.right_range));
            }
        }
        return root;
    }
};