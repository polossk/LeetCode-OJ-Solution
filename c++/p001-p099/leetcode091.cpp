// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 091                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	inline bool _(char __) { return __ != '0'; }

	inline bool _(char _1, char _2)
	{
		return _1 == '1' || (_1 == '2' && _2 <= '6');
	}
public:
	int numDecodings(string s)
	{
		int sz = s.size();
		if (sz == 0 || s[0] == '0') return 0;
		if (sz == 1) return 1;
		int ret = 0, a = 1, b = 1;
		for (int i = 1; i < sz; i++)
		{
			ret = 0;
			if (!_(s[i]) && !_(s[i - 1], s[i])) return 0;
			if (_(s[i])) ret = a;
			if (_(s[i-1], s[i])) ret += b;
			b = a; a = ret;
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
