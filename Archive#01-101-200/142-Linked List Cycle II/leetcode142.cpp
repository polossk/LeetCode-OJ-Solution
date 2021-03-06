// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 142                                                 *
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

void test() {}

int main() { test(); return 0; }
