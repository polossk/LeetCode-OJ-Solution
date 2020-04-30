// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 025                                                 *
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *reverse(ListNode *first, ListNode *last)
    {
        ListNode *prev = last;
        while (first != last)
        {
            ListNode *hoge = first->next;
            first->next = prev;
            prev = first;
            first = hoge;
        }
        return prev;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode **hoge = &head;
        ListNode *piyo = *hoge;
        ListNode *fuga = *hoge;
        for (int i = 0; i < k; i++)
        {
            if (!fuga) return piyo;
            fuga = fuga->next;
        }
        head = reverse(piyo, fuga);
        piyo->next = reverseKGroup(fuga, k);
        return head;
    }
};

void test() {}

int main() { test(); return 0; }
