# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True
        n = 1
        p = head
        while p.next:
            p = p.next
            n += 1
        if head.val != p.val:
            return False
        q = head
        f = None
        if n % 2:
            for i in range(n // 2):
                p = q
                q = p.next
                p.next = f
                f = p
            q = q.next
        else:
            for i in range(n // 2):
                p = q
                q = p.next
                p.next = f
                f = p
        while p.val == q.val:
            p = p.next
            if not p:
                return True
            q = q.next
        return False


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

            ret = Solution().isPalindrome(head)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
