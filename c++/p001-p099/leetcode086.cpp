// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 086 Partition List                                  *
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
	ListNode* partition(ListNode* head, int x)
	{
		ListNode node1(0), *hoge = &node1;
		ListNode node2(0), *fuga = &node2;
		while (head)
		{
			if (head -> val < x)
				hoge = hoge -> next = head;
			else
				fuga = fuga -> next = head;
			head = head -> next;
		}
		fuga -> next = nullptr;
		hoge -> next = node2.next;
		return node1.next;
	}
};

void test()
{

}

int main()
{

	return 0;
}
