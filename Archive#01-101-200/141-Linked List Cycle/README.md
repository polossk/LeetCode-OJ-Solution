# Linked List Cycle

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Linked_List](https://img.shields.io/badge/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode141-cpp-f34b7d.svg)   | 8 ms    | 7.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode141-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode141-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode141-java-b07219.svg) | -       | -            |

## DESCRIPTION

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.

## EXAMPLE 1

```plain
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

## EXAMPLE 2

```plain
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

## EXAMPLE 3

```plain
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

## FOLLOW UP

* Can you solve it using O(1) (i.e. constant) memory?


## SOLUTION

* 快慢指针法，快指针如果与慢指针相遇，说明有环，反之无环

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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (1)
        {
            if (fast == nullptr || fast->next == nullptr) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return true;
    }
};
```

### Python3


### Ruby


### Java

