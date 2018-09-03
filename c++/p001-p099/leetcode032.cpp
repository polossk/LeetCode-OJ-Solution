// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 032 Longest Valid Parentheses                       *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int len = s.size();
		if (len < 2) return 0;
		vector<int> dp(len, 0);
		for (int i = 1; i < len; i++)
		{
			if (s[i] == '(') continue;
			int j = i - 1 - dp[i - 1];
			if (j >= 0 && s[j] == '(')
			{
				dp[i] = dp[i - 1] + 2;
				dp[i] += (j - 1 >= 0) ? dp[j - 1] : 0;
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};

void test()
{
	Solution sol;
	cout << sol.longestValidParentheses("(()");
}

int main()
{
	test();
	return 0;
}
