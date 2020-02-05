# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        slow = dummy
        flag = False
        while head and head.next:
            if head.val != head.next.val:
                if not flag:
                    slow.next = head
                    slow = slow.next
                flag = False
            else:
                flag = True
            head = head.next
        slow.next = None if flag else head
        return dummy.next
