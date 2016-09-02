// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 010                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
	bool dfs(const string& _s, const string& _p, int i, int j)
	{
		char s = _s[i], p = _p[j];
		if (p == '\0') return s == '\0';
		if (_p[j + 1] == '*')
			return dfs(_s, _p, i, j + 2)
				|| (s != '\0' && (s == p || p =='.'))
				&& dfs(_s, _p, i + 1, j);
		else
			return (s != '\0' && (s == p || p =='.'))
				&& dfs(_s, _p, i + 1, j + 1);
	}
public:
	bool isMatch(string s, string p) { return dfs(s, p, 0, 0); }
};

void test()
{

}

int main()
{

	return 0;
}
