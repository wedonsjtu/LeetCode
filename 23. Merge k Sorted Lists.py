# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        i = 0
        le = len(lists)
        while i < le:
            if not lists[i]:
                lists.pop(i)
                le -= 1
                continue
            i += 1
        if len(lists) == 0:
            return None
        if len(lists) == 1:
            return lists[0]
        lists.sort(key=lambda x: x.val)
        head = ListNode(0)
        p = head
        while lists:
            p.next = lists[0]
            p = p.next
            if not lists[0].next:
                lists.pop(0)
                if len(lists) == 1:
                    p.next = lists[0]
                    return head.next
            else:
                lists[0] = lists[0].next
                lists.sort(key=lambda x: x.val)
        return head.next
