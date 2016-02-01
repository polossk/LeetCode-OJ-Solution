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
def add_two_numbers( l1, l2 )
	head, prev = nil, nil
	d0, d1 = 0, 0
	while (l1 != nil || l2 != nil)
		hoge = l1 == nil ? 0 : l1.val
		piyo = l2 == nil ? 0 : l2.val
		fuga = hoge + piyo + d1
		d1, d0 = fuga / 10, fuga % 10
		cur = ListNode.new(d0);
		head = cur if head == nil
		prev.next = cur unless prev == nil
		prev = cur
		l1 = l1 == nil ? nil : l1.next
		l2 = l2 == nil ? nil : l2.next
	end
	prev.next = ListNode.new(d1) if (d1 > 0)
	head
end