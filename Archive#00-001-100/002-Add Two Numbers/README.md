# Add Two Numbers

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Linked%20List](https://img.shields.io/badge/-Linked%20List-007ec6.svg) ![Math](https://img.shields.io/badge/-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode002-cpp-f34b7d.svg)   | 28 ms   | 10.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode002-py-3572A5.svg) | 84 ms   | 13.3 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode002-rb-701516.svg)   | 60 ms   | 10.1 Mb      |

## DESCRIPTION

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## EXAMPLE

```plain
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

## SOLUTION

* 链表基本操作
* 注意进位与空链表的处理

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *prev = NULL;
        int d1 = 0, d0 = 0;
        while (l1 || l2)
        {
            int hoge = l1 ? l1->val : 0;
            int piyo = l2 ? l2->val : 0;
            int fuga = hoge + piyo + d1;
            d1 = fuga / 10;
            d0 = fuga % 10;
            ListNode *cur = new ListNode(d0);
            if (!head) head = cur;
            if (prev) prev->next = cur;
            prev = cur;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (d1 > 0)
        {
            ListNode *last = new ListNode(d1);
            prev->next = last;
        }
        return head;
    }
};
```

### Python3

```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = prev = ListNode(None)
        d0, d1 = 0, 0
        while l1 or l2:
            hoge, piyo = [_.val if _ else 0 for _ in [l1, l2]]
            fuga = hoge + piyo + d1
            d1, d0 = fuga // 10, fuga % 10
            prev.next = ListNode(d0)
            prev = prev.next
            l1, l2 = [_.next if _ else None for _ in [l1, l2]]
        prev.next = ListNode(d1) if d1 > 0 else None
        return dummy.next

```

### Ruby

```ruby
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
    cur = ListNode.new(d0)
    head = cur if head == nil
    prev.next = cur unless prev == nil
    prev = cur
    l1 = l1 == nil ? nil : l1.next
    l2 = l2 == nil ? nil : l2.next
  end
  prev.next = ListNode.new(d1) if d1 > 0
  head
end
```
