# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next, p1, p2 = head, dummy, head
        while n > 0:
            p2 = p2.next
            n -= 1
        while p2:
            p1, p2 = p1.next, p2.next
        p1.next = p1.next.next
        return dummy.next
