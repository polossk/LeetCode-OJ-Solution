# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = prev = ListNode(None)
        d0, d1 = 0, 0
        while l1 or l2:
            hoge, piyo = [_.val if _ else 0 for _ in [l1, l2]]
            fuga = hoge + piyo + d1
            d1, d0 = fuga // 10, fuga % 10
            prev.next = ListNode(d0)
            prev = prev.next
            l1, l2 = [_.next if _ else None for _ in [l1, l2]]
        prev.next = ListNode(d1) if d1 > 0 else None
        return dummy.next
