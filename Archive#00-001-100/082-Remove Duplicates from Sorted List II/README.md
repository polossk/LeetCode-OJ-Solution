# Remove Duplicates from Sorted List II

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Linked%20List](https://img.shields.io/badge/-Linked%20List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode082-cpp-f34b7d.svg)   | 8 ms    | 9.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode082-py-3572A5.svg) | 36 ms   | 12.6 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode082-rb-701516.svg)   | 36 ms   | 9.3 Mb       |
| ![java](https://img.shields.io/badge/leetcode082-java-b07219.svg) | 0 ms    | 39.6 Mb      |

## DESCRIPTION

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only *distinct* numbers from the original list.

## EXAMPLE 1

```plain
Input: 1->2->3->3->4->4->5
Output: 1->2->5
```

## EXAMPLE 2

```plain
Input: 1->1->1->2->3
Output: 2->3
```

## SOLUTION

* 链表基本操作，注意处理 `next` 为空的情况
* 出现连续值则直接指针移动掉即可

## CODE

### C++

```cpp
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode **runner = &head;
        while (*runner)
        {
            if ((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                while ((*runner)->next && (*runner)->next->val == (*runner)->val)
                    (*runner)->next = (*runner)->next->next;
                (*runner) = (*runner)->next;
            }
            else runner = &((*runner)->next);
        }
        return head;
    }
};
```

### Python3

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        slow = dummy
        flag = False
        while head and head.next:
            if head.val != head.next.val:
                if not flag:
                    slow.next = head
                    slow = slow.next
                flag = False
            else:
                flag = True
            head = head.next
        slow.next = None if flag else head
        return dummy.next
```

### Ruby

```ruby
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
```

### Java

```java
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode fast = head, slow = dummy;
        slow.next = fast;
        while (fast != null) {
            while (fast.next != null && fast.val == fast.next.val) {
                fast = fast.next;
            }
            if (slow.next != fast) {
                slow.next = fast.next;
            } else {
                slow = slow.next;
            }
            fast = fast.next;
        }
        return dummy.next;
    }
}
```
