# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def mergeKLists(self, lists):
		"""
		:type lists: List[ListNode]
		:rtype: ListNode
		"""
		minHeap, head = [(node.val, node) for node in lists if node], ListNode(0)
		heapq.heapify(minHeap)
		p = head
		while minHeap:
			_, node = heapq.heappop(minHeap)
			if node.next: heapq.heappush(minHeap, (node.next.val, node.next))
			p.next, node.next = node, None
			p = p.next
		return head.next