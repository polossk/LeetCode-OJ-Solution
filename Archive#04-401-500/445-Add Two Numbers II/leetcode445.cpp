// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 445                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test() {}

int main() { test(); return 0; }
