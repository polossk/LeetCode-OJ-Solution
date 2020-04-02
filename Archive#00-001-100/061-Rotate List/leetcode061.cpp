// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 061                                                 *
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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *cur = head;
        int cnt = 0, len = 0;
        while (cur != NULL)
        {
            if (cur->next == NULL)
            {
                len = ++cnt;
                cur->next = head;
                cur = head;
                cnt = 0;
                k %= len;
            }
            if (cnt == len - k - 1)
            {
                ListNode *ret = cur->next;
                cur->next = nullptr;
                return ret;
            }
            cnt++;
            cur = cur->next;
        }
        return head;
    }
};

void test() {}

int main() { test(); return 0; }
