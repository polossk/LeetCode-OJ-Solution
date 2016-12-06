// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 014                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string ret;
		if (!strs.size()) return ret;
		for (int i = 0; i < strs[0].size(); i++)
		{
			char curr = strs[0][i];
			for (int j = 1; j < strs.size(); j++)
			{
				if (i > strs[j].size() - 1 || curr != strs[j][i]) return ret;
			}
			ret.push_back(curr);
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
