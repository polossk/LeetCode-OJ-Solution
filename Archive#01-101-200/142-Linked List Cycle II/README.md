# Linked List Cycle II

![Medium](../../materials/-Medium-f0ad4e.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode142-cpp-f34b7d.svg)   | 12 ms   | 7.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode142-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode142-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode142-java-b07219.svg) | -       | -            |

## DESCRIPTION

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.

## EXAMPLE 1

```plain
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

## EXAMPLE 2

```plain
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

## EXAMPLE 3

```plain
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

## NOTE

Do not modify the linked list.

## FOLLOW UP

* Can you solve it without using extra space?


## SOLUTION

* 快慢指针法。不妨假设，圈外的长度为 L，每一圈的长度为 K。
* 假设，快指针与慢指针第一次相遇时，两者在距离环的起点 d 的位置相遇，此时快指针的路程是慢指针的两倍，即 `(L + n1 * K + d) == 2 * (L + n2 * K + d)`
* 把上面的等式展开，有 `(n1 - n2) * K = L + n2 * K + d`，此时的等式右端恰好为慢指针所跑的路程
* 所以让快指针从头开始，与慢指针以相同的速度重新运动，显然，当再跑了 `L + n2 * K + d` 的路程时，两指针会再次相遇，而此时相遇的位置恰好为环的起点

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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (1)
        {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        fast = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
```

### Python3


### Ruby


### Java

