// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 007                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	int reverse(int x)
	{
		int ret = 0;
		while ( x != 0)
		{
			int digit = x % 10;
			int hoge = ret * 10 + digit;
			if ((hoge - digit) / 10 != ret) return 0;
			ret = hoge; x /= 10;
		}
		return ret;
	}
};

void test()
{

}

int main()
{

	return 0;
}
