// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 227                                                 *
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
		auto ch2i = [](char ch) -> int { return ch - '0'; };
		int sign = 1, ret = 0, top = 0, tmp = 0;
		char last = '+';

		for (int i = 0, sz = s.size(); i <= sz; )
		{
			if (isspace(s[i])) { i++; continue; }
			if (s[i] == '-' || s[i] == '+' || !s[i])
			{
				ret += top * sign;
				last = s[i++];
				sign = last == '+' ? 1 : -1;
				top = 1;
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				last = s[i++];
			}
            if (i >= sz) break;
			if (isdigit(s[i]))
			{
				tmp = 0;
				while (i < sz && isdigit(s[i]))
					tmp = tmp * 10 + ch2i(s[i++]);
				if (last == '*') top *= tmp;
				else if (last == '/') top /= tmp;
				else top = tmp; 
			}
		}
		return ret;
	}
};

void test() {}

int main() { test(); return 0; }
