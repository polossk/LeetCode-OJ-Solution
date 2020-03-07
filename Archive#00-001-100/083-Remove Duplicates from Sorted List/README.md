# Remove Duplicates from Sorted List

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Linked_List](https://img.shields.io/badge/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode083-cpp-f34b7d.svg)   | 16 ms   | 9.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode083-py-3572A5.svg) | 40 ms   | 12.7 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode083-rb-701516.svg)   | 36 ms   | 9.4 Mb       |
| ![java](https://img.shields.io/badge/leetcode083-java-b07219.svg) | 0 ms    | 45.3 Mb      |

## DESCRIPTION

Given a sorted linked list, delete all duplicates such that each element appear only *once*.

## EXAMPLE 1

```plain
Input: 1->1->2
Output: 1->2
```

## EXAMPLE 2

```plain
Input: 1->1->2->3->3
Output: 1->2->3
```

## SOLUTION

* 链表基本操作，注意处理 `next` 为空的情况

## CODE

### C++

```cpp
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!(head && head -> next)) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};
```

### Python3

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        node = head
        while node:
            while node.next and node.next.val == node.val:
                node.next = node.next.next
            node = node.next
        return head
```

### Ruby

```ruby
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
```

### Java

```java
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if ( (head == null) || (head.next == null) )
            return head;
        head.next = deleteDuplicates(head.next);
        return head.val == head.next.val ? head.next : head;
    }
}
```
