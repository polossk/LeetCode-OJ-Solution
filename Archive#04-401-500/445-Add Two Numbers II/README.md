# Add Two Numbers II

![Medium](../../materials/-Medium-f0ad4e.svg) ![Linked_List](../../materials/链表-Linked_List-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode445-cpp-f34b7d.svg)   | 36 ms   | 12.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode445-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode445-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## FOLLOW UP

What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

## EXAMPLE

```plain
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```

## SOLUTION

* 堆栈收集链表数据

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
    stack<int> stackize(ListNode *head)
    {
        stack<int> ret;
        ListNode *iter = head;
        while (iter != nullptr)
        {
            ret.push(iter->val);
            iter = iter->next;
        }
        return ret;
    }
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1 = stackize(l1), s2 = stackize(l2);
        ListNode *ret = nullptr;
        int carry = 0;
        auto auto_pop = [](stack<int> &s)->int {
            if (s.empty()) return 0;
            int ret = s.top(); s.pop();
            return ret;
        };
        while ((!s1.empty()) || (!s2.empty()) || (carry))
        {
            int lhs = auto_pop(s1), rhs = auto_pop(s2);
            int val = lhs + rhs + carry;
            carry = val / 10;
            val %= 10;
            ListNode *ptr = new ListNode(val);
            ptr->next = ret;
            ret = ptr;
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

### Java
