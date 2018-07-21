# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        ans = []
        if not root:
            return ans

        def bTP(r, s):
            if not r:
                return
            if not r.left and not r.right:
                ans.append(s)
                return
            if r.left:
                bTP(r.left, s + '->' + str(r.left.val))
            if r.right:
                bTP(r.right, s + '->' + str(r.right.val))

        bTP(root, str(root.val))
        return ans


def stringToTreeNode(input):
    input = input.strip()
    input = input[1:-1]
    if not input:
        return None

    inputValues = [s.strip() for s in input.split(',')]
    root = TreeNode(int(inputValues[0]))
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(inputValues):
        node = nodeQueue[front]
        front = front + 1

        item = inputValues[index]
        index = index + 1
        if item != "null":
            leftNumber = int(item)
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(inputValues):
            break

        item = inputValues[index]
        index = index + 1
        if item != "null":
            rightNumber = int(item)
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)
    return root


def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            p = stringToTreeNode(line)

            ret = Solution().binaryTreePaths(p)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()