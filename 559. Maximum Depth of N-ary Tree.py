# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root:
            return 0
        l = [root]
        d = 0
        while l:
            le = len(l)
            while le > 0:
                n = l.pop(0)
                for child in n.children:
                    l.append(child)
                le -= 1
            d += 1
        return d