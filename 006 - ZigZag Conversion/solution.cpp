// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 006 ZigZag Conversion                               *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;
		string ret;
		int inc = (numRows - 1) << 1;
		int len = s.size();
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < len + numRows; j += inc)
			{
				if (j > i && j - i < len && i != 0 && i != numRows - 1)
					ret += s[j - i];
				if (j + i < len) ret += s[j + i];
			}
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
