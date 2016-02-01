# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def merge_two_lists( l1, l2 )
	head = ListNode.new(0)
	p = head
	while (l1 != nil && l2 != nil)
		if l1.val < l2.val then
			p.next, l1 = l1, l1.next
		else
			p.next, l2 = l2, l2.next
		end
		p = p.next
	end
	p.next = (l1 == nil) ? l2 : l1;
	head.next
end