// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 019 Remove Nth Node From End of List                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode start(0); start.next = head;
		ListNode *p1 = &start, *p2 = head;
		while (n--) p2 = p2 -> next;
		while (p2 != NULL)
		{
			p2 = p2 -> next;
			p1 = p1 -> next;
		}
		p2 = p1 -> next;
		p1 -> next = p1 -> next -> next;
		delete p2;
		return start.next;
	}
};

void test()
{

}

int main()
{

	return 0;
}
