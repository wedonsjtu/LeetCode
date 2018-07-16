# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return TreeNode(nums[0])
        ma = nums[0]
        mai = 0
        for i in range(1, len(nums)):
            if nums[i] > ma:
                mai = i
                ma = nums[i]
        root = TreeNode(nums[mai])
        root.left = self.constructMaximumBinaryTree(nums[:mai])
        root.right = self.constructMaximumBinaryTree(nums[mai+1:])
        return root
