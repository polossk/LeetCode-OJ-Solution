# Rotate List

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Linked_List](https://img.shields.io/badge/链表-Linked_List-007ec6.svg) ![Two_Pointers](https://img.shields.io/badge/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode061-cpp-f34b7d.svg)   | 12 ms   | 7.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode061-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode061-rb-701516.svg)   | 36 ms   | 9.4 Mb       |

## DESCRIPTION

Given a linked list, rotate the list to the right by *k* places, where *k* is non-negative.

## EXAMPLE 1

```plain
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```

## EXAMPLE 2

```plain
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```

## SOLUTION

* 链表基本操作，注意处理细节

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *cur = head;
        int cnt = 0, len = 0;
        while (cur != NULL)
        {
            if (cur->next == NULL)
            {
                len = ++cnt;
                cur->next = head;
                cur = head;
                cnt = 0;
                k %= len;
            }
            if (cnt == len - k - 1)
            {
                ListNode *ret = cur->next;
                cur->next = nullptr;
                return ret;
            }
            cnt++;
            cur = cur->next;
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

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def rotate_right(head, k)
  cnt, len, cur = 0, 0, head
  while (cur != nil) do
    if (cur.next == nil) then
      len, cnt = cnt + 1, 0
      cur.next, cur = head, head
      k %= len
    end
    if (cnt == len - k - 1) then
      ret, cur.next = cur.next, nil
      return ret
    end
    cnt, cur = cnt + 1, cur.next
  end
  return head
end
```

### Java

```java
```
