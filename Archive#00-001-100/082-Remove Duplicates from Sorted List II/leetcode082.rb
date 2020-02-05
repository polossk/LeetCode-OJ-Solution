# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}
def delete_duplicates(head)
  dummy = ListNode.new(0)
  fast, slow = head, dummy
  slow.next = fast
  while (fast != nil) do
    while (fast.next != nil) && (fast.val == fast.next.val) do
      fast = fast.next
    end
    if (slow.next != fast) then
      slow.next = fast.next
    else
      slow = slow.next
    end
    fast = fast.next
  end
  dummy.next
end