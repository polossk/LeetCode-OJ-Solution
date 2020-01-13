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
  return head unless head && head.next
  if head.val != head.next.val then
    head.next = delete_duplicates(head.next)
  else
    head = delete_duplicates(head.next)
  end
  return head
end
