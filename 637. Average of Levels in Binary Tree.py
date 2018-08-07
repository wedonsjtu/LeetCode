# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        ans = []
        num = []

        def aOL(r, depth):
            if not r:
                return
            if depth < len(ans):
                ans[depth] += r.val
                num[depth] += 1
            else:
                ans.append(r.val)
                num.append(1)
            aOL(r.left, depth + 1)
            aOL(r.right, depth + 1)

        aOL(root, 0)
        return [(ans[i] / num[i]) for i in range(len(ans))]
