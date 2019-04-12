// <!-- encoding UTF-8 --!>
/*****************************************************************************
 *                     ----Stay Hungry Stay Foolish----                       *
 *   @author :   Shen                                                         *
 *   @name   :   Leetcode 002                                                 *
 *****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *prev = NULL;
        int d1 = 0, d0 = 0;
        while (l1 || l2)
        {
            int hoge = l1 ? l1->val : 0;
            int piyo = l2 ? l2->val : 0;
            int fuga = hoge + piyo + d1;
            d1 = fuga / 10;
            d0 = fuga % 10;
            ListNode *cur = new ListNode(d0);
            if (!head) head = cur;
            if (prev) prev->next = cur;
            prev = cur;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (d1 > 0)
        {
            ListNode *last = new ListNode(d1);
            prev->next = last;
        }
        return head;
    }
};

void test() {}

int main()
{
    test();
    return 0;
}
