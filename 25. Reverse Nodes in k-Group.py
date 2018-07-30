# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        p = head
        f = None
        if k == 1:
            return head
        if k == 2:
            if not head or not head.next:
                return head
            p = head
            head = head.next
            while p and p.next:
                q = p.next
                p.next = q.next
                q.next = p
                q = p
                p = p.next
                if p and p.next:
                    q.next = p.next
            return head
        for i in range(k):
            if not p:
                return head
            p = p.next
        q = p = head
        for i in range((k-1)//2):
            q = p.next
            p.next = f
            r = p
            p = q.next
            q.next = r
            f = q
        if (k-1) % 2:
            r = p.next
            p.next = q
            head.next = self.reverseKGroup(r.next, k)
            r.next = p
            return r
        else:
            head.next = self.reverseKGroup(p.next, k)
            p.next = q
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
            head = stringToListNode(line);
            line = next(lines)
            k = int(line);

            ret = Solution().reverseKGroup(head, k)

            out = listNodeToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()