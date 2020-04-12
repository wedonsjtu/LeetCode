# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, ro):
        """
        :type ro: TreeNode
        :rtype: int
        """
        if not ro:
            return 0
        if (not ro.left) and (not ro.right):
            return 1
        elif (not ro.left) and ro.right:
            return 1 + self.maxDepth(ro.right)
        elif ro.left and (not ro.right):
            return 1 + self.maxDepth(ro.left)
        else:
            return 1 + max(self.maxDepth(ro.right), self.maxDepth(ro.left))

    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        depth = self.maxDepth(root)
        if depth == 1:
            return [[str(root.val)]]
        le = 2 ** depth - 1
        ans = [[""] * le for x in range(depth)]

        def pT(r, line, location):
            if not r:
                return
            print(location)
            ans[line][location] = str(r.val)
            pT(r.left, line + 1, location - 2 ** (depth - line - 2))
            pT(r.right, line + 1, location + 2 ** (depth - line - 2))

        pT(root, 0, 2 ** (depth - 1) - 1)
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
            root = stringToTreeNode(line);

            ret = Solution().printTree(root)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()