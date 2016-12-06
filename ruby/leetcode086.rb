# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} x
# @return {ListNode}
def partition(head, x)
	hoge = node1 = ListNode.new(0)
	fuga = node2 = ListNode.new(0)
	while head
		if head.val < x then
			hoge.next = head
			hoge = hoge.next
		else
			fuga.next = head
			fuga = fuga.next
		end
		head = head.next
	end
	fuga.next, hoge.next = nil, node2.next
	node1.next
end