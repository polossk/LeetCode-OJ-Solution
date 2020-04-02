# Definition for singly-linked list.
# class ListNode
#   attr_accessor :val, :next
#   def initialize(val)
#     @val = val
#     @next = nil
#   end
# end

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists( lists )
  head = ListNode.new(0)
  p = head
  data = []
  lists.each { |e|
    while (e != nil)
      data << e.val
      e = e.next
    end
  }
  data.sort.each { |e|
    p.next = ListNode.new(e)
    p = p.next
  }
  head.next
end