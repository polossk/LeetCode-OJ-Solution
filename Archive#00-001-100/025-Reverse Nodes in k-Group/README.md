# Reverse Nodes in k-Group

![Hard](../../materials/-Hard-e05d44.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode025-cpp-f34b7d.svg)   | 16 ms   | 10 Mb        |
| ![python](https://img.shields.io/badge/leetcode025-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode025-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.

*k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes in the end should remain as it is.

## NOTE

* Only constant extra memory is allowed.
* You may not alter the values in the list's nodes, only nodes itself may be changed.

## EXAMPLE

```plain
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
```

## SOLUTION

* 每 k 个元素翻转一次，注意处理不够的情况

## CODE

### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *reverse(ListNode *first, ListNode *last)
    {
        ListNode *prev = last;
        while (first != last)
        {
            ListNode *hoge = first->next;
            first->next = prev;
            prev = first;
            first = hoge;
        }
        return prev;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode **hoge = &head;
        ListNode *piyo = *hoge;
        ListNode *fuga = *hoge;
        for (int i = 0; i < k; i++)
        {
            if (!fuga) return piyo;
            fuga = fuga->next;
        }
        head = reverse(piyo, fuga);
        piyo->next = reverseKGroup(fuga, k);
        return head;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java
