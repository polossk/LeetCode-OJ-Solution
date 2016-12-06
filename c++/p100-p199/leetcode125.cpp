// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 125 Valid Palindrome                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	bool isPalindrome(string s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			while (!isalnum(s[i]) && i < j) i++;
			while (!isalnum(s[j]) && i < j) j--;
			if (tolower(s[i]) != tolower(s[j])) return false;
		}
		return true;
	}
};

void test()
{

}

int main()
{

	return 0;
}
