# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p = head = ListNode(0)
        n1 = l1
        n2 = l2
        j = 0
        while n1 and n2:
            vals = n1.val + n2.val + j
            n1 = n1.next
            n2 = n2.next
            q = ListNode(vals % 10)
            j = vals // 10
            p.next = q
            p = q
        while n1:
            vals = n1.val + j
            n1 = n1.next
            q = ListNode(vals % 10)
            j = vals // 10
            p.next = q
            p = q
        while n2:
            vals = n2.val + j
            n2 = n2.next
            q = ListNode(vals % 10)
            j = vals // 10
            p.next = q
            p = q
        if j == 1:
            q = ListNode(1)
            p.next = q
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

            ret = Solution().addTwoNumbers(l1, l2)

            out = listNodeToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()