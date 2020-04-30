# Remove Nth Node From End of List

![Medium](../../materials/-Medium-f0ad4e.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode019-cpp-f34b7d.svg)   | 6 ms    | 6.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode019-py-3572A5.svg) | 36 ms   | 13.9 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode019-rb-701516.svg)   | 72 ms   | 9.5 Mb       |

## DESCRIPTION

Given a linked list, remove the *n*-th node from the end of list and return its head.

## EXAMPLE

```plain
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```

## NOTE

Given n will always be valid.

## FOLLOW UP

Could you do this in one pass?

## SOLUTION

* 链表处理基本题

## CODE

### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode start(0); start.next = head;
        ListNode *p1 = &start, *p2 = head;
        while (n--) p2 = p2->next;
        while (p2 != NULL)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        p2 = p1->next;
        p1->next = p1->next->next;
        delete p2;
        return start.next;
    }
};
```

### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next, p1, p2 = head, dummy, head
        while n > 0:
            p2 = p2.next
            n -= 1
        while p2:
            p1, p2 = p1.next, p2.next
        p1.next = p1.next.next
        return dummy.next   
```

### Ruby

```ruby
# Definition for singly-linked list.
# class ListNode
#   attr_accessor :val, :next
#   def initialize(val)
#     @val = val
#     @next = nil
#   end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
  start = ListNode.new(0)
  start.next, p1, p2 = head, start, head
  n.times { p2 = p2.next }
  while (p2 != nil)
    p1, p2 = p1.next, p2.next
  end
  p1.next = p1.next.next
  start.next
end
```
