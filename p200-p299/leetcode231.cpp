// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 231 Power of Two                                    *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	bool isPowerOfTwo(int n)
	{
		if (n < 1) return false;
		return 4294967296 % n == 0 ? 1 : 0;
	}
};

void test()
{

}

int main()
{

	return 0;
}
