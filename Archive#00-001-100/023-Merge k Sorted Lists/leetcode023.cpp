// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 023                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test() {}

int main() { test(); return 0; }
