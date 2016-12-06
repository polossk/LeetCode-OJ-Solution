// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 224                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
	int calculate(string s)
	{
		if (s.size() < 1) return 0;
		vector<int> signs(2, 1);
		auto ch2i = [](char ch) -> int { return ch - '0'; };
		int ret = 0, tmp = 0;

		for (int i = 0, sz = s.size(); i < sz; )
		{
			if (isspace(s[i])) { i++; continue; }
			if (isdigit(s[i]))
			{
				tmp = 0;
				while (i < sz && isdigit(s[i]))
					tmp = tmp * 10 + ch2i(s[i++]);
				ret += signs.back() * tmp;
				signs.pop_back();
			}
			else if (s[i] == ')') { signs.pop_back(); i++; }
			else if (s[i] != ' ')
				signs.push_back(signs.back() * (s[i++] == '-' ? -1 : 1));
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
