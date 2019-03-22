# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end( head, n )
    start = ListNode.new(0)
    start.next, p1, p2 = head, start, head
    n.times { p2 = p2.next }
    while (p2 != nil)
        p1, p2 = p1.next, p2.next
    end
    p1.next = p1.next.next
    start.next
end