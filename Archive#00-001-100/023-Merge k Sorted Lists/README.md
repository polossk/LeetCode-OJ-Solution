# Binary Tree Maximum Path Sum

![Hard](../../materials/-Hard-e05d44.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg) ![Divide_and_Conquer](../../materials/分治法-Divide_and_Conquer-007ec6.svg) ![Heap](../../materials/堆-Heap-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode023-cpp-f34b7d.svg)   | 24 ms   | 12.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode023-py-3572A5.svg) | 120 ms  | 16 Mb        |
| ![ruby](https://img.shields.io/badge/leetcode023-rb-701516.svg)   | 52 ms   | 10.8 Mb      |

## DESCRIPTION

Merge *k* sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

## EXAMPLE

```plain
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```

## SOLUTION

* 很容易想到只要保持每次都从所有链表中的首元素中选取他们的最小值就能保持有序性
* 那么就可以两两递归合并
* 当然也可以直接用每条链的首元素建立最小堆，然后依次取出当前堆顶的首元素转成链表输出

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
    ListNode *mergeKLists(vector<ListNode*> &lists)
    {
        if (lists.empty()) return nullptr;
        int sz = lists.size();
        vector<ListNode*> head(lists);
        while (sz > 1)
        {
            for (int i = 0; (i << 1) < sz; i++)
                head[i] = mergeTwoLists(head[i << 1],
                    (i << 1) + 1 >= sz ? nullptr : head[(i << 1) + 1]
                );
            sz = (sz + 1) >> 1;
        }
        return head[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = (l1 == nullptr) ? l2 : l1;
        p = head;
        head = head->next;
        delete p;
        return head;
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

class Dummy(tuple):
    def __lt__(self, other):
        return self[0] < other[0]

import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        minHeap, head = [Dummy((node.val, node)) for node in lists if node], ListNode(0)
        heapq.heapify(minHeap)
        p = head
        while minHeap:
            _, node = heapq.heappop(minHeap)
            if node.next: heapq.heappush(minHeap, Dummy(((node.next.val, node.next))))
            p.next, node.next = node, None
            p = p.next
        return head.next
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

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists( lists )
  head = ListNode.new(0)
  p = head
  data = []
  lists.each { |e|
    while (e != nil)
      data << e.val
      e = e.next
    end
  }
  data.sort.each { |e|
    p.next = ListNode.new(e)
    p = p.next
  }
  head.next
end
```
