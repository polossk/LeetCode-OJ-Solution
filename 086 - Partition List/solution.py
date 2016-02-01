# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def partition(self, head, x):
		"""
		:type head: ListNode
		:type x: int
		:rtype: ListNode
		"""
		hoge = node1 = ListNode(0)
		fuga = node2 = ListNode(0)
		while head:
			if head.val < x:
				hoge.next = head
				hoge = hoge.next
			else:
				fuga.next = head
				fuga = fuga.next
			head = head.next
		fuga.next, hoge.next = None, node2.next
		return node1.next