// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 143 Reorder List                                    *
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
	void reorderList(ListNode* head)
	{
		if (!head || !head->next) return;
		ListNode *p1 = head, *p2 = head -> next;
		while (p2 && p2 -> next)
		{
			p1 = p1 -> next;
			p2 = p2 -> next -> next;
		}
		ListNode *head2 = p1 -> next;
		p1 -> next = NULL;
		p2 = head2 -> next;
		head2 -> next = NULL;
		while (p2)
		{
			p1 = p2 -> next;
			p2 -> next = head2;
			head2 = p2;
			p2 = p1;
		}
		for (p1 = head, p2 = head2; p1; )
		{
			ListNode *hoge = p1 -> next;
			p1 -> next = p2;
			p1 = p2;
			p2 = hoge;
		}
	}
};

void test()
{

}

int main()
{

    return 0;
}
