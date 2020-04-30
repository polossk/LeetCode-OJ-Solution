# Merge Two Sorted Lists

![Easy](../../materials/-Easy-5cb85c.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode021-cpp-f34b7d.svg)   | 0 ms    | 6.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode021-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode021-rb-701516.svg)   | 36 ms   | 9.6 Mb       |

## DESCRIPTION

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

## EXAMPLE

```plain
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

## SOLUTION

* 链表基本操作，注意处理细节

## CODE

### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **hoge = &head, *piyo, *fuga;
        while ((piyo = *hoge) && (fuga = piyo->next))
        {
            piyo->next = fuga->next;
            fuga->next = piyo;
            *hoge = fuga;
            hoge = &(piyo->next);
        }
        return head;
    }
};
```

### Python3

```python
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
```

### Java

```java
```
