// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 082                                                 *
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

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode **runner = &head;
        while (*runner)
        {
            if ((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                while ((*runner)->next && (*runner)->next->val == (*runner)->val)
                    (*runner)->next = (*runner)->next->next;
                (*runner) = (*runner)->next;
            }
            else runner = &((*runner)->next);
        }
        return head;
    }
};

void test() {}

int main() { test(); return 0; }
