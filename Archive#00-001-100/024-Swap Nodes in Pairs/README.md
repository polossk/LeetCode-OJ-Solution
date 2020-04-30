# Swap Nodes in Pairs

![Medium](../../materials/-Medium-f0ad4e.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg)
## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode024-cpp-f34b7d.svg)   | 12 ms   | 7.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode024-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode024-rb-701516.svg)   | 32 ms   | 9.2 Mb       |

## DESCRIPTION

Given a linked list, swap every two adjacent nodes and return its head.

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

## EXAMPLE

```plain
Given 1->2->3->4, you should return the list as 2->1->4->3.
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
```

### Java

```java
```
