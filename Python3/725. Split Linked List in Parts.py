# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        if k == 1:
            return [root]
        if not root:
            return [None] * k
        if not root.next:
            return [root] + [None] * (k - 1)
        n = 1
        p = root
        while p.next:
            p = p.next
            n += 1
        g = n // k
        y = n % k
        ans = []
        for i in range(k):
            ans.append(root)
            for i in range(g-1):
                root = root.next
            if y > 0 and g != 0:
                root = root.next
                y -= 1
            if not root:
                ans.extend([None] * (k - len(ans)))
                return ans
            p = root
            root = root.next
            p.next = None
        return ans


def stringToIntegerList(input):
    return eval(input)


def stringToListNode(input):
    # Generate list from the input
    numbers = stringToIntegerList(input)

    # Now convert that list into linked list
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for number in numbers:
        ptr.next = ListNode(number)
        ptr = ptr.next

    ptr = dummyRoot.next
    return ptr


def listNodeToString(node):
    if not node:
        return "[]"

    result = ""
    while node:
        result += str(node.val) + ", "
        node = node.next
    return "[" + result[:-2] + "]"


def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            root = stringToListNode(line)
            line = next(lines)
            k = int(line)

            ret = Solution().splitListToParts(root, k)

            out = [listNodeToString(i) for i in ret]
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()