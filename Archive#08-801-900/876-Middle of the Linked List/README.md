# Middle of the Linked List

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Linked_List](https://img.shields.io/badge/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode876-cpp-f34b7d.svg)   | 0 ms    | 6.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode876-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode876-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode876-java-b07219.svg) | -       | -            |

## DESCRIPTION

Given a non-empty, singly linked list with head node `head`, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

## EXAMPLE 1

```plain
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
```

## EXAMPLE 2

```plain
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
```

## NOTE

* The number of nodes in the given list will be between `1` and `100`.


## SOLUTION

* 快慢指针法，快指针走到链表尾部时，慢指针的位置就是中点位置

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
```

### Python3


### Ruby


### Java

