# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        n1 = l1
        n2 = l2
        if not n2:
            return n1
        if not n1:
            return n2
        head = ListNode(0)
        p = head
        while True:
            if n1.val >= n2.val:
                q = ListNode(n2.val)
                p.next = q
                p = q
                n2 = n2.next
                if not n2:
                    while True:
                        q = ListNode(n1.val)
                        p.next = q
                        p = q
                        n1 = n1.next
                        if not n1:
                            p = head.next
                            del head
                            return p
            else:
                q = ListNode(n1.val)
                p.next = q
                p = q
                n1 = n1.next
                if not n1:
                    while True:
                        q = ListNode(n2.val)
                        p.next = q
                        p = q
                        n2 = n2.next
                        if not n2:
                            p = head.next
                            del head
                            return p


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
            l1 = stringToListNode(line);
            line = next(lines)
            l2 = stringToListNode(line);

            ret = Solution().mergeTwoLists(l1, l2)

            out = listNodeToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
