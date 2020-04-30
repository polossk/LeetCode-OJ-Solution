# Reorder List

![Medium](../../materials/-Medium-f0ad4e.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode143-cpp-f34b7d.svg)   | 40 ms   | 14.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode143-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode143-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode143-java-b07219.svg) | -       | -            |

## DESCRIPTION

Given a singly linked list L: `L_0→L_1→…→L_{n-1}→L_n`,
reorder it to: `L_0→L_n→L_1→L_{n-1}→L_2→L_{n-2}→…`

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

## EXAMPLE 1

```plain
Given 1->2->3->4, reorder it to 1->4->2->3.
```

## EXAMPLE 2

```plain
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
```

## NOTE

Do not modify the linked list.

## FOLLOW UP

* Can you solve it without using extra space?

## SOLUTION

* 见缝插针

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
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next) return;
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode *head2 = p1->next;
        p1->next = NULL;
        p2 = head2->next;
        head2->next = NULL;
        while (p2)
        {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        for (p1 = head, p2 = head2; p1; )
        {
            ListNode *hoge = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = hoge;
        }
    }
};
```

### Python3


### Ruby


### Java

