# Partition List

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Linked%20List](https://img.shields.io/badge/-Linked%20List-007ec6.svg) ![Two%20Pointers](https://img.shields.io/badge/-Two%20Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode082-cpp-f34b7d.svg)   | 8 ms    | 9.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode082-py-3572A5.svg) | 36 ms   | 12.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode082-rb-701516.svg)   | 36 ms   | 9.4 Mb       |
| ![java](https://img.shields.io/badge/leetcode082-java-b07219.svg) | 0 ms    | 38.6 Mb      |

## DESCRIPTION

Given a linked list and a value *x*, partition it such that all nodes less than *x* come before nodes greater than or equal to *x*.

You should preserve the original relative order of the nodes in each of the two partitions.

## EXAMPLE

```plain
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```

## SOLUTION

* 链表基本操作，维护两个指针分别处理即可

## CODE

### C++

```cpp
class Solution {
public:
	ListNode *partition(ListNode *head, int x)
	{
		ListNode node1(0), *hoge = &node1;
		ListNode node2(0), *fuga = &node2;
		while (head)
		{
			if (head->val < x)
				hoge = hoge->next = head;
			else
				fuga = fuga->next = head;
			head = head->next;
		}
		fuga->next = nullptr;
		hoge->next = node2.next;
		return node1.next;
	}
};
```

### Python3

```python
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        hoge = node1 = ListNode(0)
        fuga = node2 = ListNode(0)
        while head:
            if head.val < x:
                hoge.next = head
                hoge = hoge.next
            else:
                fuga.next = head
                fuga = fuga.next
            head = head.next
        fuga.next, hoge.next = None, node2.next
        return node1.next
```

### Ruby

```ruby
# @param {ListNode} head
# @return {ListNode}
def partition(head, x)
  hoge = node1 = ListNode.new(0)
  fuga = node2 = ListNode.new(0)
  while head
    if head.val < x then
      hoge.next = head
      hoge = hoge.next
    else
      fuga.next = head
      fuga = fuga.next
    end
    head = head.next
  end
  fuga.next, hoge.next = nil, node2.next
  node1.next
end
```

### Java

```java
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode node1 = new ListNode(0), node2 = new ListNode(0);
        ListNode hoge = node1, fuga = node2;
        while (head != null) {
            if (head.val < x)
                hoge = hoge.next = head;
            else
                fuga = fuga.next = head;
            head = head.next;
        }
        fuga.next = null;
        hoge.next = node2.next;
        return node1.next;
    }
}
```
