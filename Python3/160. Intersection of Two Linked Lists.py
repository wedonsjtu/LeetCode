# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type headA: ListNode
        :type headB: ListNode
        :rtype: ListNode
        """
        if not headA:
            return headA
        if not headB:
            return headB
        p1 = headA
        l1 = 0
        l2 = 0
        while p1:
            l1 += 1
            p1 = p1.next
        p1 = headB
        while p1:
            l2 += 1
            p1 = p1.next
        while l1 < l2:
            l2 -= 1
            headB = headB.next
        while l1 > l2:
            l1 -= 1
            headA = headA.next
        p1 = headA
        while True:
            while headA.val != headB.val:
                headA = headA.next
                if not headA:
                    return None
                headB = headB.next
                p1 = headA
            while headA.val == headB.val:
                headA = headA.next
                if not headA:
                    return p1
                headB = headB.next


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
            head = stringToListNode(line);
            line = next(lines)
            head1 = stringToListNode(line);

            ret = Solution().getIntersectionNode(head, head1)

            out = listNodeToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()