# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        first = head
        second = ListNode(0)
        second.next = head
        while True:
            for i in range(n):
                first = first.next
            if not first:
                if second.next == head:
                    head = head.next
                    return head
                second.next = second.next.next
                return head
            second = second.next
            first = second.next


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
            head = stringToListNode(line)
            line = next(lines)
            n = int(line)

            ret = Solution().removeNthFromEnd(head, n)

            out = listNodeToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()