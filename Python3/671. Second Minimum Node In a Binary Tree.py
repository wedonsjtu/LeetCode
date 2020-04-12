# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ans = []

        def fSMV(r):
            if not r:
                return
            if len(ans) == 0:
                ans.append(r.val)
            elif len(ans) == 1:
                if ans[0] > r.val:
                    ans.append(r.val)
                elif ans[0] < r.val:
                    ans.insert(0, r.val)
            else:
                if ans[0] > r.val > ans[1]:
                    ans[0] = r.val
                elif r.val < ans[1]:
                    ans[1], ans[0] = r.val, ans[1]
            fSMV(r.left)
            fSMV(r.right)

        fSMV(root)
        if len(ans) <= 1:
            return -1
        return ans[0]


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

            ret = Solution().findSecondMinimumValue(root)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
