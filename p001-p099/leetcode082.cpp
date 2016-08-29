// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 082 Remove Duplicates from Sorted List II           *
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
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode **runner = &head;
		while (*runner)
		{
			if ((*runner) -> next && (*runner) -> next -> val == (*runner) -> val)
			{
				while ((*runner) -> next && (*runner) -> next -> val == (*runner) -> val)
					(*runner) -> next = (*runner) -> next -> next;
				(*runner) = (*runner) -> next;
			}
			else runner = &((*runner) -> next);
		}
		return head;
	}
};

/**
#define RN      (*runner) -> next
#define RV      (*runner) -> val
#define RNN     RN -> next
#define RNV     RN -> val

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode **runner = &head;
		while (*runner)
		{
			if (RN && RNV == RV)
			{
				while (RN && RNV == RV)
					RN = RNN;
				(*runner) = RN;
			}
			else runner = &(RN);
		}
		return head;
	}
};

#undef RNV
#undef RNN
#undef RV
#undef RN
*/


void test()
{

}

int main()
{

	return 0;
}
