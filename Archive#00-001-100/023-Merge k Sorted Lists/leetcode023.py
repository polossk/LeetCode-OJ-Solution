# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Dummy(tuple):
    def __lt__(self, other):
        return self[0] < other[0]

import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        minHeap, head = [Dummy((node.val, node)) for node in lists if node], ListNode(0)
        heapq.heapify(minHeap)
        p = head
        while minHeap:
            _, node = heapq.heappop(minHeap)
            if node.next: heapq.heappush(minHeap, Dummy(((node.next.val, node.next))))
            p.next, node.next = node, None
            p = p.next
        return head.next