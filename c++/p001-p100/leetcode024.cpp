// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 024 Swap Nodes in Pairs                             *
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **hoge = &head;
        ListNode *piyo;
        ListNode *fuga;
        while ((piyo = *hoge) && (fuga = piyo->next))
        {
            piyo->next = fuga->next;
            fuga->next = piyo;
            *hoge = fuga;
            hoge = &(piyo->next);
        }
        return head;
    }
};

void test() {}

int main() { test(); return 0; }
