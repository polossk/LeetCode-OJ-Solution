# Definition for singly-linked list.
# class ListNode
#   attr_accessor :val, :next
#   def initialize(val)
#     @val = val
#     @next = nil
#   end
# end

# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)
  dummy = ListNode.new(0)
  dummy.next = head
  fuga, hoge = dummy, head
  # before: fuga -> [hoge -> piyo] -> ...
  # after:  fuga -> [piyo -> hoge] -> ...
  while (hoge != nil) do
    if hoge.next == nil then
      break
    end
    piyo = hoge.next
    fuga.next = piyo
    hoge.next = piyo.next
    piyo.next = hoge
    fuga = hoge
    hoge = hoge.next
  end
  dummy.next
end