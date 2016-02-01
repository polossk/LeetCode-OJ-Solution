# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def rotate_right(head, k)
	cnt, len, cur = 0, 0, head
	while (cur != nil) do
		if (cur.next == nil) then
			cnt = cnt + 1
			len = cnt
			cur.next = head
			cur = head
			cnt, k = 0, k % len
		end
		if (cnt == len - k - 1) then
			ret = cur.next
			cur.next = nil
			return ret
		end
		cnt, cur = cnt + 1, cur.next
	end
	return head
end